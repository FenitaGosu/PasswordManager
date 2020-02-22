#pragma once

#include "PasswordLogicLib/AccountInfo/AccountInfoDec.h"

namespace PasswordLogic {

class IDataController
{
public:
	virtual ~IDataController() = default;

	virtual AccountsInfo GetAccountsInfo() const = 0;
	virtual void AddNewAccount(const AccountInfo& info) = 0;
};

}
