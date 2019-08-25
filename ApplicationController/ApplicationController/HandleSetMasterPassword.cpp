#include "UIProtocol/Interfaces/IUIProtocol.h"
#include "UIProtocol/Interfaces/IUIProtocolClient.h"

#include "UIProtocol/ProtocolFactory/UIProtocolFactory.h"

#include "PasswordUI/Interfaces/IUIController.h"

#include "Interfaces/IApplicationSettings.h"

#include "ApplicationController.h"

using namespace Controller;
using namespace UIProtocol;

void ApplicationController::HandleSetMasterPassword(IApplicationSettings* settings)
{
	const auto protocol = m_uiProtocolFactory->CreateProtorol();

	m_uiController->ShowSetMasterPasswordDialog(protocol->ToUIProtocol());
}
