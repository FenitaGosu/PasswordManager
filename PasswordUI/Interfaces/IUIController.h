#pragma once

#include <memory>

namespace UIProtocol {
class IUIProtocol;
}

namespace PasswordUI {

class IUIController
{
public:
	virtual ~IUIController() = default;

	virtual void ShowSetMasterPasswordDialog(UIProtocol::IUIProtocol& protocol) const = 0;
};

}
