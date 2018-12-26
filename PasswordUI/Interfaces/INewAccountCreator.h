#pragma once

#include "PasswordLogic/AccountInfo/AccountInfoDec.h"

namespace PasswordUI {

class INewAccountCreator
{
public:
	virtual ~INewAccountCreator() = default;
	virtual void CreateNewAccount(const PasswordLogic::PreviewAccountInfo& previewInfo, const PasswordLogic::AccountInfo& accountInfo) = 0;
};

}
