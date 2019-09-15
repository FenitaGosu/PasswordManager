#include <map>
#include <functional>
#include <string>

#include "Tools/StreamWrapper/StreamWrapper.h"

#include "PasswordGenerator/Interfaces/IPasswordGenerator.h"

#include "PasswordGenerator/Enums/ComponentsOfPassword.h"

#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "PasswordLogic/Interfaces/IDataController.h"

#include "PasswordUI/Interfaces/IUIController.h"

#include "UIProtocol/ProtocolFactory/UIProtocolFactory.h"

#include "Interfaces/IApplicationSettings.h"

#include "Enums/Action.h"

#include "ApplicationController.h"

using namespace Controller;

struct ApplicationController::Impl
{
	std::map<std::string, std::function<void(IApplicationSettings*)>> actionHandles;
};

ApplicationController::ApplicationController()
	: m_impl(std::make_unique<Impl>())
{
}

ApplicationController::~ApplicationController() = default;

void ApplicationController::Setup(std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector, std::unique_ptr<PasswordLogic::IDataController>&& dataController, std::unique_ptr<Tools::StreamWrapper>&& streamWrpper, std::unique_ptr<PasswordGenerator::IPasswordGenerator>&& passwordGenerator, std::unique_ptr<PasswordUI::IUIController>&& uiController, std::unique_ptr<UIProtocol::UIProtocolFactory>&& uiProtocolFactory)
{
	m_credentialIncpector	= std::move(credentialIncpector);
	m_dataController		= std::move(dataController);
	m_streamWrpper			= std::move(streamWrpper);
	m_passwordGenerator		= std::move(passwordGenerator);
	m_uiController			= std::move(uiController);
	m_uiProtocolFactory		= std::move(uiProtocolFactory);

	SetupActionHandles();
}

void ApplicationController::Run(std::unique_ptr<IApplicationSettings>&& settings)
{
	if (!CheckMasterPassword(settings.get()))
		return;

	HandleImpl(settings.get());
}

void ApplicationController::SetupActionHandles()
{
	m_impl->actionHandles =
	{
		{ Action::SET_MASTER_PASSWORD, std::bind(&ApplicationController::HandleSetMasterPassword, this, std::placeholders::_1)}
	};
}

bool ApplicationController::CheckMasterPassword(IApplicationSettings* settings) const
{
	if (m_credentialIncpector->IsNeedSetPassword())
		if (settings->GetAction() == Action::SET_MASTER_PASSWORD)
		{
			return true;
		}
		else
		{
			m_streamWrpper->Write(" ", MASTER_PASSWORD_NOT_SET);
			return false;
		}
	else
		if (m_credentialIncpector->CheckPassword(settings->GetMasterPassword()))
		{
			return true;
		}
		else
		{
			m_streamWrpper->Write(" ", MASTER_PASSWORD_INVALID);
			return false;
		}
}

void ApplicationController::HandleImpl(IApplicationSettings* settings)
{
	const auto it = m_impl->actionHandles.find(settings->GetAction());

	if (it == m_impl->actionHandles.cend())
	{
		m_streamWrpper->Write(" ", ACTION_NOT_FOUND);
		return;
	}

	it->second(settings);
}