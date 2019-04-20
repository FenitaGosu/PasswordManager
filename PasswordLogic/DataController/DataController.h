#pragma once

#include <memory>

#include "AccountInfo/AccountInfoDec.h"

namespace PasswordLogic {

class IDataSource;

class DataController
{
public:
	DataController(const std::shared_ptr<IDataSource>& dataSource);

	AccountsInfo GetAccountsInfo() const;
	void AddNewAccount(const AccountInfo& previewInfo);

private:
	std::shared_ptr<IDataSource> m_dataSource;
};

}
