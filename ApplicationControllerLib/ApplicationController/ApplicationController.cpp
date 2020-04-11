#include <map>
#include <functional>
#include <string>
#include <exception>

#include "ApplicationController.h"

using namespace Controller;

void ApplicationController::Setup(std::unique_ptr<IApiProxy>&& passwordApi, std::unique_ptr<IDataStream>&& dataStream)
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

		m_dataStream->PushData(m_passwordApi->HandleMessage(data));
	}
}
