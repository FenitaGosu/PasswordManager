#pragma once

#include "PasswordUI/Interfaces/IUIController.h"

namespace PasswordUI {

	class UIController : public IUIController
	{
	public:
		void ShowSetMasterPasswordDialog() const override;
	};

}
