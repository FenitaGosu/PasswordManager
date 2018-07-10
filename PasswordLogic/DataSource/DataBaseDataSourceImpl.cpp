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
		isFirstStart = status == IDataBaseConnection::OpenStatus::OpenNew;
	}
	std::unique_ptr<IDataBaseConnection> connection;
	bool isFirstStart = false;
};

DataBaseDataSourceImpl::DataBaseDataSourceImpl(const std::string& path)
	: m_impl(std::make_unique<Impl>(path))
{
}

DataBaseDataSourceImpl::~DataBaseDataSourceImpl() = default;

bool DataBaseDataSourceImpl::IsFisrstStart() const noexcept
{
	return m_impl->isFirstStart;
}

std::string DataBaseDataSourceImpl::GeCurrentMainPassword() const
{
	return std::string();
}

void DataBaseDataSourceImpl::SetCurrentMainPassword(const std::string& password)
{

}
