#pragma once

#include <memory>

#include "PasswordLogicLib/Interfaces/IDataSource.h"
#include "PasswordLogicLib/Interfaces/ICredentialSource.h"

namespace PasswordLogic {

class DataBaseDataSourceImpl;

class DataBaseDataSource
	: public IDataSource
	, public ICredentialSource
{
public:
	DataBaseDataSource(const std::string& path);
	~DataBaseDataSource();

/// ICredentialSource
	bool IsNeedSetPassword() const noexcept override;
	std::string GeCurrentMainPassword() const override;
	void SetCurrentMainPassword(const std::string& password) override;

/// IDataSource
	void GetAccountsInfo(IDataContainer& dataContainer) const override;
	void AddNewAccount(const IDataContainer& previewData) override;

private:
	std::unique_ptr<DataBaseDataSourceImpl> m_dataBase;
};

}
