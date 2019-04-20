#pragma once

#include "AccountInfo/AccountInfoDec.h"

namespace PasswordLogic {

class IDataController
{
public:
	virtual ~IDataController() = default;

	virtual AccountsInfo GetAccountsInfo() const = 0;
	virtual void AddNewAccount(const AccountInfo& info) = 0;
};

}
