#include "Tools/Same/Same.h"

#include "DataContainer/PreviewAccountsDataContainer.h"

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

void DataBaseDataSource::AddNewAccount(const IDataContainer& previewData)
{
	m_dataBase->AddNewAccount(previewData.GetDataList());
}

void DataBaseDataSource::GetPreviewAccountsInfo(IDataContainer& dataContainer) const
{
	dataContainer.AddDataList(m_dataBase->GetPreviewAccountsInfo());
}
