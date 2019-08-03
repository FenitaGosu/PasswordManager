#pragma once

namespace PasswordUI {

class IUIController
{
public:
	virtual ~IUIController() = default;

	virtual void ShowSetMasterPasswordDialog() const = 0;
};

}
