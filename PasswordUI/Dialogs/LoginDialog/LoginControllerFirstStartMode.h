#pragma once

#include "BaseLoginController.h"

namespace PasswordUI {

class LoginControllerFirstStartMode : public BaseLoginController
{
public:
	LoginControllerFirstStartMode(PasswordLogic::ICredentialsInspector* const inspector, ILoginDialog* const dialog);

	void Setup() override;

private:
	void OnSaveClicked() override;
	void OnCancelClicked()override;
};

}
