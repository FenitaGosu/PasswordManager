#pragma once

#include <memory>

namespace PasswordUI {

class IUIProtocolDataTransfer;

class IUIController
{
public:
	virtual ~IUIController() = default;

	virtual void ShowSetMasterPasswordDialog(std::unique_ptr<IUIProtocolDataTransfer>&& protocol) const = 0;
};

}
