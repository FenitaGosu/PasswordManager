#pragma once

#include "BaseLoginController.h"

namespace PasswordUI {

class LoginControllerSetPasswordMode : public BaseLoginController
{
public:
	LoginControllerSetPasswordMode(PasswordLogic::ICredentialsInspector* const inspector, ILoginDialog* const dialog);

	void Setup() override;

private:
	void OnSaveClicked() override;
	void OnCancelClicked()override;
};

}
