#include <map>
#include <functional>
#include <string>
#include <exception>

#include "ApiProxyLib/ApiProxy/ApiProxy.h"
#include "ApiProxyLib/ApiProxyMethod/ApiProxyMethod.h"

#include "PasswordKit/ApiProxyMethodExecuter/ApiProxyMethodExecuter.h"

#include "PasswordLogicApiInfoLib/ApiParameters.h"

#include "ApplicationController.h"

using namespace PasswordKit;

namespace {

	template <class T>
	std::unique_ptr<Proxy::IApiProxyMethod> CreateMethod(const Tools::ISerializeFactory& factory, PasswordLogic::IPasswordApi* api)
	{
		return std::make_unique<Proxy::ApiProxyMethod<T, PasswordKit::ApiProxyMethodExecuter<T>>>(factory, ApiProxyMethodExecuter<T>(api));
	}

}

void ApplicationController::Setup(std::unique_ptr<Tools::ISerializeFactory>&& serializeFactory, std::unique_ptr<PasswordLogic::IPasswordApi>&& api, std::unique_ptr<IDataStream>&& dataStream)
{
	m_serializeFactory	= std::move(serializeFactory);
	m_api				= std::move(api);
	m_dataStream		= std::move(dataStream);
	m_proxyApi			= std::make_unique<Proxy::ApiProxy>(*m_serializeFactory);
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

		m_dataStream->PushData(m_proxyApi->HandleMessage(data));
	}
}

void ApplicationController::RegisterMethods()
{
	m_proxyApi->RegisterMethod(CreateMethod<PasswordLogicApiInfo::SetMainPasswordMethodInfo>(*m_serializeFactory, m_api.get()));
}
