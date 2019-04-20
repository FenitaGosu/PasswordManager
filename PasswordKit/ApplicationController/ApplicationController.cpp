#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "ApplicationController.h"

using namespace PasswordKit;

struct ApplicationController::Impl
{
	std::unique_ptr<PasswordLogic::ICredentialsInspector> credentialIncpector;
};

ApplicationController::ApplicationController()
	: m_impl(std::make_unique<Impl>())
{
}

ApplicationController::~ApplicationController() = default;

void ApplicationController::Setup(std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector)
{
	m_impl->credentialIncpector = std::move(credentialIncpector);
}

void ApplicationController::Run(std::unique_ptr<IApplicationSettings>&& settings)
{
}
