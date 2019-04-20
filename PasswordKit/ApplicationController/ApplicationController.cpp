#include "PasswordLogic/Interfaces/ICredentialsInspector.h"
#include "PasswordLogic/Interfaces/IDataController.h"

#include "ApplicationController.h"

using namespace PasswordKit;

struct ApplicationController::Impl
{
	std::unique_ptr<PasswordLogic::ICredentialsInspector> credentialIncpector;
	std::unique_ptr<PasswordLogic::IDataController> dataController;
};

ApplicationController::ApplicationController()
	: m_impl(std::make_unique<Impl>())
{
}

ApplicationController::~ApplicationController() = default;

void ApplicationController::Setup(std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector, std::unique_ptr<PasswordLogic::IDataController>&& dataController)
{
	m_impl->credentialIncpector = std::move(credentialIncpector);
	m_impl->dataController = std::move(dataController);
}

void ApplicationController::Run(std::unique_ptr<IApplicationSettings>&& settings)
{
}
