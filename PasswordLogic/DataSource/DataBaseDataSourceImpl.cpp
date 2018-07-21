#include <iostream>
#include <string>

#include <QString>

#include "DataBase/Interfaces/IDataBaseConnection.h"
#include "DataBase/Interfaces/IQuery.h"
#include "DataBase/Interfaces/ITransactionManager.h"

#include "DataBase/DataBaseConnectionSQL/DataBaseConnectionSQL.h"
#include "DataBase/TransactionManagerSQL/TransactionGuard.h"

#include "DataBaseCreator.h"
#include "DataBaseMigrator.h"
#include "DataBaseArtifacts.h"
#include "DataBaseDataSourceImpl.h"

using namespace PasswordLogic;
using namespace DataBase;

struct DataBaseDataSourceImpl::Impl
{
	Impl(const std::string& path)
		: connection(std::make_unique<DataBaseConnectionSQL>(QString::fromStdString(path)))
	{
		const auto status = connection->OpenConnection();

		if (status == IDataBaseConnection::OpenStatus::OpenNew)
		{
			DataBaseCreator::FillDataBase(connection);
			isNeedSetPassword = true;
		}
		else
		{
			isNeedSetPassword = GetPassword().empty() ? true : false;
			DataBaseMigrator::MigrateDataBase(connection);
		}
	}

	std::string GetPassword() const
	{
		std::string password;
		bool success = false;
		const auto transaction = connection->GetTransactionManager();
		const auto guard = transaction->MakeGuard(success);

		try
		{
			const auto query = transaction->GetQuery();

			query->Exec(DataBaseArtifacts::SELECT_CONSTANT, { {DataBaseArtifacts::NAME, DataBaseArtifacts::MAIN_PASSWORD_CONSTANT} } );

			if (query->Next())
				password = query->Value(query->IndexOf(DataBaseArtifacts::VALUE_INDEX).value()).toString().toStdString();

			success = true;
		}
		catch (std::exception& exp)
		{
			std::cerr << exp.what();
		}

		return password;
	}

	void SetPassword(const std::string& password)
	{
		bool success = false;
		const auto transaction = connection->GetTransactionManager();
		const auto guard = transaction->MakeGuard(success);

		try
		{
			transaction->GetQuery()->Exec(DataBaseArtifacts::UPDATE_CONSTANT, { {DataBaseArtifacts::NAME, DataBaseArtifacts::MAIN_PASSWORD_CONSTANT}, {DataBaseArtifacts::VALUE, QString::fromStdString(password)} });
			success = true;
		}
		catch (std::exception& exp)
		{
			std::cerr << exp.what();
		}
	}

public:
	std::unique_ptr<IDataBaseConnection> connection;
	bool isNeedSetPassword = false;
};

DataBaseDataSourceImpl::DataBaseDataSourceImpl(const std::string& path)
	: m_impl(std::make_unique<Impl>(path))
{
}

DataBaseDataSourceImpl::~DataBaseDataSourceImpl() = default;

bool DataBaseDataSourceImpl::IsNeedSetPassword() const noexcept
{
	return m_impl->isNeedSetPassword;
}

std::string DataBaseDataSourceImpl::GeCurrentMainPassword() const
{
	return m_impl->GetPassword();
}

void DataBaseDataSourceImpl::SetCurrentMainPassword(const std::string& password)
{
	if (m_impl->isNeedSetPassword)
		m_impl->isNeedSetPassword = false;

	m_impl->SetPassword(password);
}
