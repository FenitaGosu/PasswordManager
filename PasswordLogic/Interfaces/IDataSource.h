#pragma once

#include <string>

#include "AccountInfo/AccountInfoDec.h"

namespace PasswordLogic {

class IDataContainer;

class IDataSource
{
public:
	virtual ~IDataSource() = default;

	virtual void GetPreviewAccountsInfo(IDataContainer& dataContainer) = 0;
};

}
