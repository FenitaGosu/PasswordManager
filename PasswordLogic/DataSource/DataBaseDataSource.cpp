#include "DataBaseDataSource.h"
#include "DataBaseDataSourceImpl.h"

using namespace PasswordLogic;

DataBaseDataSource::DataBaseDataSource(const std::string& path)
	: m_dataBase(std::make_unique<DataBaseDataSourceImpl>(path))
{
}

DataBaseDataSource::~DataBaseDataSource() = default;

bool DataBaseDataSource::IsNeedSetPassword() const noexcept
{
	return m_dataBase->IsNeedSetPassword();
}

std::string DataBaseDataSource::GeCurrentMainPassword() const
{
	return m_dataBase->GeCurrentMainPassword();
}

void DataBaseDataSource::SetCurrentMainPassword(const std::string& password)
{
	m_dataBase->SetCurrentMainPassword(password);
}
