#include <iostream>
#include <string>
#include <cassert>

#include "ToolsLib/Same/Same.h"

#include "DataBaseLib/Interfaces/IDataBaseConnection.h"
#include "DataBaseLib/Interfaces/IQuery.h"
#include "DataBaseLib/Interfaces/ITransactionManager.h"

#include "DataBaseLib/DataBaseConnectionSQL/DataBaseConnectionSQL.h"
#include "DataBaseLib/TransactionManagerSQL/TransactionGuard.h"

#include "PasswordLogicLib/Parameters.h"

#include "DataBaseCreator.h"
#include "DataBaseMigrator.h"
#include "DataBaseArtifacts.h"
#include "DataBaseDataSourceImpl.h"

using namespace PasswordLogic;
using namespace DataBase;

struct DataBaseDataSourceImpl::Impl
{
	Impl(const std::string& path)
		: connection(std::make_unique<DataBaseConnectionSQL>(path))
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
				password = std::any_cast<std::string>(query->Value(query->IndexOf(DataBaseArtifacts::VALUE_INDEX).value()));

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
			transaction->GetQuery()->Exec(DataBaseArtifacts::UPDATE_CONSTANT, { {DataBaseArtifacts::NAME, DataBaseArtifacts::MAIN_PASSWORD_CONSTANT}, {DataBaseArtifacts::VALUE, password} });
			success = true;
		}
		catch (std::exception& exp)
		{
			std::cerr << exp.what();
		}
	}

	DataList GetAccountsInfo() const
	{
		DataList info;

		bool success = false;
		const auto transaction = connection->GetTransactionManager();
		const auto guard = transaction->MakeGuard(success);

		try
		{
			const auto query = transaction->GetQuery();

			query->Exec(DataBaseArtifacts::SELECT_ACCOUNT);

			const auto indexId		= query->IndexOf(DataBaseArtifacts::ID_INDEX).value();
			const auto indexName	= query->IndexOf(DataBaseArtifacts::NAME_INDEX).value();
			const auto indexType	= query->IndexOf(DataBaseArtifacts::TYPE_INDEX).value();

			while (query->Next())
			{
				Data mapInfo;

				mapInfo.emplace(Parameters::PARAM_ID,	std::any_cast<std::string>(query->Value(indexId)));
				mapInfo.emplace(Parameters::PARAM_NAME, std::any_cast<std::string>(query->Value(indexName)));
				mapInfo.emplace(Parameters::PARAM_TYPE, std::any_cast<std::string>(query->Value(indexType)));

				info.push_back(mapInfo);
			}

			success = true;
		}
		catch (std::exception& exp)
		{
			std::cerr << exp.what();
		}

		return info;
	}

	void AddNewAccount(const DataList& previewData)
	{
		bool success = false;
		const auto transaction = connection->GetTransactionManager();
		const auto guard = transaction->MakeGuard(success);

		try
		{
			const auto query = transaction->GetQuery();
			const auto getValue = [](const Data& data, const std::string& key)
			{
				const auto it = data.find(key);
				assert(it != data.cend());
				return it->second.Get<const std::string&>();
			};

			/// insert account data
			{
				query->SetTextQuery(DataBaseArtifacts::INSERT_ACCOUNT);

				for (const auto& info : previewData)
				{
					query->SetParametersQuery({ {DataBaseArtifacts::ID,		getValue(info, PasswordLogic::Parameters::PARAM_ID)},
												{DataBaseArtifacts::NAME,	getValue(info, PasswordLogic::Parameters::PARAM_NAME)},
												{DataBaseArtifacts::TYPE,	getValue(info, PasswordLogic::Parameters::PARAM_TYPE)},
											  });

					query->Exec();
				}
			}

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

DataList DataBaseDataSourceImpl::GetAccountsInfo() const
{
	return m_impl->GetAccountsInfo();
}

void DataBaseDataSourceImpl::AddNewAccount(const DataList& previewData)
{
	m_impl->AddNewAccount(previewData);
}
