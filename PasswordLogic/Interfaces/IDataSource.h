#pragma once

#include <string>

#include "AccountInfo/AccountInfoDec.h"

namespace PasswordLogic {

class IDataContainer;

class IDataSource
{
public:
	virtual ~IDataSource() = default;

	virtual void GetPreviewAccountsInfo(IDataContainer& dataContainer) const = 0;
	virtual void AddPreviewAccountsInfo(const IDataContainer& dataContainer) = 0;
};

}
