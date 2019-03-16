#pragma once

#include "PasswordLogic/AccountInfo/AccountInfoDec.h"

namespace PasswordUI {

class ICurrentAccountInfoProvider
{
public:
	virtual ~ICurrentAccountInfoProvider() = default;
	virtual std::pair<PasswordLogic::PreviewAccountInfo, PasswordLogic::AccountInfo> GetCurrentAccountInfo() = 0;
};

}
