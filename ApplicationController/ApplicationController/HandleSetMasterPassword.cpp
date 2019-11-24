#include <utility>

#include "UIProtocol/Interfaces/IUIProtocol.h"
#include "UIProtocol/Interfaces/IUIProtocolClient.h"

#include "UIProtocol/Enums/ProtocolType.h"

#include "PasswordUI/Interfaces/IUIController.h"

#include "Interfaces/IApplicationSettings.h"

#include "ApplicationController.h"

using namespace Controller;
using namespace UIProtocol;

namespace {
	std::string SettingsToJson(IApplicationSettings* settings)
	{
		/// @todo
		return std::string();
	}
}

void ApplicationController::HandleSetMasterPassword(IApplicationSettings* settings)
{
	const auto protocol = CreateProtocol(ProtocolType::JSON, SettingsToJson(settings), {});

	m_uiController->ShowSetMasterPasswordDialog(protocol->ToUIProtocol());

	/// @todo
	///protocol->GetResult()
}
