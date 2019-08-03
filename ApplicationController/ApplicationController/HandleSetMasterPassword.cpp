
#include "PasswordUI/UIController/UIController.h"

#include "Interfaces/IApplicationSettings.h"

#include "ApplicationController.h"

using namespace Controller;

void ApplicationController::HandleSetMasterPassword(IApplicationSettings* settings)
{
	m_uiController->ShowSetMasterPasswordDialog();
}
