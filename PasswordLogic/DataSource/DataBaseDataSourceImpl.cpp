#include <QString>

#include "DataBase/Interfaces/IDataBaseConnection.h"
#include "DataBase/DataBaseConnectionSQL/DataBaseConnectionSQL.h"

#include "DataBaseDataSourceImpl.h"

using namespace PasswordLogic;
using namespace DataBase;

struct DataBaseDataSourceImpl::Impl
{
	Impl(const std::string& path)
		: connection(std::make_unique<DataBaseConnectionSQL>(QString::fromStdString(path)))
	{
		const auto status = connection->OpenConnection();
		/// @TODO нелья завязваться только на наличие файла, нужно проверить, есть ли вообще пароль в бд
		isNeedSetPassword = status == IDataBaseConnection::OpenStatus::OpenNew;
	}
	std::unique_ptr<IDataBaseConnection> connection;
	bool isNeedSetPassword = false;
};

DataBaseDataSourceImpl::DataBaseDataSourceImpl(const std::string& path)
	: m_impl(std::make_unique<Impl>(path))
{
}

DataBaseDataSourceImpl::~DataBaseDataSourceImpl()
{
	m_impl->connection->CloseConnection();
	if (m_impl->isNeedSetPassword)
		m_impl->connection->RemoveStorage();
}

bool DataBaseDataSourceImpl::IsNeedSetPassword() const noexcept
{
	return m_impl->isNeedSetPassword;
}

std::string DataBaseDataSourceImpl::GeCurrentMainPassword() const
{
	return std::string();
}

void DataBaseDataSourceImpl::SetCurrentMainPassword(const std::string& password)
{
	if (m_impl->isNeedSetPassword)
		m_impl->isNeedSetPassword = false;
}
