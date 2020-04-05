#include <map>
#include <functional>
#include <string>
#include <exception>

#include "ApplicationController.h"

using namespace Controller;

struct ApplicationController::Impl
{
};

ApplicationController::ApplicationController()
	: m_impl(std::make_unique<Impl>())
{
}

ApplicationController::~ApplicationController() = default;

void ApplicationController::Setup(std::unique_ptr<PasswordLogic::IPasswordApi>&& passwordApi, std::unique_ptr<IDataStream>&& dataStream)
{
	m_passwordApi	= std::move(passwordApi);
	m_dataStream	= std::move(dataStream);
}

void ApplicationController::Run(std::unique_ptr<IApplicationSettings>&& settings)
{
	RunActionLoop();
}

void ApplicationController::RunActionLoop()
{
	while(true)
	{
		const std::string data = m_dataStream->WaitData();

		if (data == m_dataStream->GetFinishStatus())
			return;

		/// todo parse data
	}
}
