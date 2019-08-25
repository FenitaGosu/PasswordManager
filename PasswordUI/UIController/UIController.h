#pragma once

#include "PasswordUI/Interfaces/IUIController.h"

namespace PasswordUI {

class UIController : public IUIController
{
public:
	void ShowSetMasterPasswordDialog(UIProtocol::IUIProtocol& protocol) const override;
};

}
