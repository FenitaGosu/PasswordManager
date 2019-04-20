#pragma once

#include <string>

#include "AccountInfo/AccountInfoDec.h"

namespace PasswordLogic {

class IDataContainer;

class IDataSource
{
public:
	virtual ~IDataSource() = default;

	virtual void GetAccountsInfo(IDataContainer& dataContainer) const = 0;
	virtual void AddNewAccount(const IDataContainer& previewData) = 0;
};

}
