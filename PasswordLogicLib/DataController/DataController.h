#pragma once

#include <memory>

#include "PasswordLogicLib/AccountInfo/AccountInfoDec.h"
#include "PasswordLogicLib/Interfaces/IDataController.h"

namespace PasswordLogic {

class IDataSource;

class DataController : public IDataController
{
public:
	DataController(const std::shared_ptr<IDataSource>& dataSource);

	AccountsInfo GetAccountsInfo() const override;
	void AddNewAccount(const AccountInfo& info) override;

private:
	std::shared_ptr<IDataSource> m_dataSource;
};

}
