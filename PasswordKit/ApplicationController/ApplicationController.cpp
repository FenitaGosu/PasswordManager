#include "ApplicationController.h"

using namespace PasswordKit;

struct ApplicationController::Impl
{

};

ApplicationController::ApplicationController()
{
}

PasswordKit::ApplicationController::~ApplicationController() = default;

void ApplicationController::Run(std::unique_ptr<IApplicationSettings>&& settings)
{
}
