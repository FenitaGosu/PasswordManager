#include <map>
#include <functional>
#include <string>

#include "Tools/StreamWrapper/StreamWrapper.h"
#include "Tools/StringFormat/StringFormat.h"

#include "PasswordGenerator/Interfaces/IPasswordGenerator.h"

#include "PasswordGenerator/Enums/ComponentsOfPassword.h"

#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "PasswordLogic/Interfaces/IDataController.h"

#include "Interfaces/IApplicationSettings.h"

#include "Enums/Action.h"

#include "ApplicationController.h"

using namespace Controller;

namespace {
constexpr int MIN_PASSWORD_SIZE = 4;
}

struct ApplicationController::Impl
{
	std::unique_ptr<PasswordLogic::ICredentialsInspector> credentialIncpector;
	std::unique_ptr<PasswordLogic::IDataController> dataController;
	std::unique_ptr<Tools::StreamWrapper> streamWrpper;
	std::unique_ptr<PasswordGenerator::IPasswordGenerator> passwordGenerator;

	std::map<Action, std::function<void(IApplicationSettings*)>> actionHandles;
};

ApplicationController::ApplicationController()
	: m_impl(std::make_unique<Impl>())
{
}

ApplicationController::~ApplicationController() = default;

void ApplicationController::Setup(std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector, std::unique_ptr<PasswordLogic::IDataController>&& dataController, std::unique_ptr<Tools::StreamWrapper>&& streamWrpper, std::unique_ptr<PasswordGenerator::IPasswordGenerator>&& passwordGenerator)
{
	m_impl->credentialIncpector = std::move(credentialIncpector);
	m_impl->dataController = std::move(dataController);
	m_impl->streamWrpper = std::move(streamWrpper);
	m_impl->passwordGenerator = std::move(passwordGenerator);

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
		{ Action::SetMasterPassword, std::bind(&ApplicationController::HandleSetMasterPassword, this, std::placeholders::_1)}
	};
}

bool ApplicationController::CheckMasterPassword(IApplicationSettings* settings) const
{
	if (m_impl->credentialIncpector->IsNeedSetPassword())	
		if (settings->GetAction() == Action::SetMasterPassword)
		{
			return true;
		}
		else
		{
			m_impl->streamWrpper->Write(" ", MASTER_PASSWORD_NOT_SET);
			return false;
		}
	else	
		if (m_impl->credentialIncpector->CheckPassword(settings->GetMasterPassword()))
		{
			return true;
		}
		else
		{
			m_impl->streamWrpper->Write(" ", MASTER_PASSWORD_INVALID);
			return false;
		}
}

std::string ApplicationController::GeneratePassword() const
{
	m_impl->streamWrpper->Write(" ", Tools::StringFormat::Format(SYMBOLS_NAMBER, MIN_PASSWORD_SIZE));
	
	int answer;
	m_impl->streamWrpper->Read(answer);
	
	answer = answer >= MIN_PASSWORD_SIZE ? answer : MIN_PASSWORD_SIZE;
	
	const auto pas = m_impl->passwordGenerator->Generate({ PasswordGenerator::ComponentsOfPassword::LowerCase, PasswordGenerator::ComponentsOfPassword::UpperCase, PasswordGenerator::ComponentsOfPassword::Numerals, PasswordGenerator::ComponentsOfPassword::SpecialSymbols }, answer, 1).front();
	
	m_impl->streamWrpper->Write(" ", Tools::StringFormat::Format(GENERATED_PASSWORD, pas.c_str()));

	return pas;
}

std::string ApplicationController::ReadPassword() const
{
	m_impl->streamWrpper->Write(" ", Tools::StringFormat::Format(INPUT_PASSWORD, MIN_PASSWORD_SIZE));

	std::string answer;
	m_impl->streamWrpper->Read(answer);

	/// @todo check empty password
	return answer;
}

void ApplicationController::HandleImpl(IApplicationSettings* settings)
{
	const auto it = m_impl->actionHandles.find(settings->GetAction());

	if (it == m_impl->actionHandles.cend())
	{
		m_impl->streamWrpper->Write(" ", ACTION_NOT_FOUND);
		return;
	}

	it->second(settings);
}

void ApplicationController::HandleSetMasterPassword(IApplicationSettings* settings)
{	
	m_impl->streamWrpper->Write(" ", GENERATE_PASSWORD_OR_INPUT);

	std::string answer;
	m_impl->streamWrpper->Read(answer);

	std::string newPassword;

	while (true)
	{
		if (answer == "g")
		{
			newPassword = GeneratePassword();
			break;
		}

		if (answer == "i")
		{
			newPassword = ReadPassword();
			break;
		}

		return;
	}	

	m_impl->credentialIncpector->SetPassword(newPassword);
	m_impl->streamWrpper->Write(" ", PASSWORD_CHANGED);
}
