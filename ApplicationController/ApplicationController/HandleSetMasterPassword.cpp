#include <utility>

#include "UIProtocol/Interfaces/IUIProtocol.h"
#include "UIProtocol/Interfaces/IUIProtocolClient.h"

#include "UIProtocol/Enums/ProtocolType.h"

#include "UIProtocol/ProtocolFactory/UIProtocolFactory.h"

#include "PasswordUI/Interfaces/IUIController.h"

#include "UIProtocol/ProtocolFactory/UIProtocolFactory.h"

#include "Interfaces/IApplicationSettings.h"

#include "ApplicationController.h"

using namespace Controller;
using namespace UIProtocol;

namespace {
	std::string SettingsToJson(IApplicationSettings* settings)
	{
		return std::string();
	}

	void ProtocolBuilder(const std::unique_ptr<IUIProtocolClient>& protocol, UIProtocol::ProtocolType type, IApplicationSettings* settings)
	{
		protocol->SetType(type);

		switch (type)
		{
			case UIProtocol::ProtocolType::JSON:
				protocol->SetMessage(SettingsToJson(settings));
			default:
				break;
		}
	}
}

void ApplicationController::HandleSetMasterPassword(IApplicationSettings* settings)
{
	const auto[type, protocol] = m_uiProtocolFactory->CreateProtorol();

	ProtocolBuilder(protocol, type, settings);

	m_uiController->ShowSetMasterPasswordDialog(protocol->ToUIProtocol());
}
