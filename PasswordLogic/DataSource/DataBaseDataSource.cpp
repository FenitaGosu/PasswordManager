#include "DataBaseDataSource.h"
#include "DataBaseDataSourceImpl.h"

using namespace PasswordLogic;

DataBaseSource::DataBaseSource(const std::string& path)
	: m_dataBase(std::make_unique<DataBaseDataSourceImpl>(path))
{
}

DataBaseSource::~DataBaseSource() = default;

bool DataBaseSource::IsFisrstStart() const noexcept
{
	return false;
}

std::string DataBaseSource::GeCurrentMainPassword() const
{
	return m_dataBase->GeCurrentMainPassword();
}

void DataBaseSource::SetCurrentMainPassword(const std::string& password)
{
	m_dataBase->SetCurrentMainPassword(password);
}
