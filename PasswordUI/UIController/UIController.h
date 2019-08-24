#pragma once

#include "PasswordUI/Interfaces/IUIController.h"

namespace PasswordUI {

class IUIProtocolDataTransfer;

class UIController : public IUIController
{
public:
	void ShowSetMasterPasswordDialog(std::unique_ptr<IUIProtocolDataTransfer>&& protocol) const override;
};

}
