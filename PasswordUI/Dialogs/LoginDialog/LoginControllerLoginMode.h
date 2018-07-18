#pragma once

#include "BaseLoginController.h"

namespace PasswordUI {

class LoginControllerLoginMode : public BaseLoginController
{
	Q_OBJECT

public:
	LoginControllerLoginMode(PasswordLogic::ICredentialsInspector* const inspector, ILoginDialog* const dialog);

	void Setup() override;

private:
	void OnOkClicked() override;
	void OnExitClicked() override;
	void OnSaveClicked() override;
	void OnCancelClicked() override;
	void OnNewPasswordClicked() override;
};

}
