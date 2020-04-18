#include "ToolsLib/StringFormat/StringFormat.h"

#include "PasswordLogicApiInfoLib/ApiParameters.h"

#include "PasswordKit/ApiProxyMethod/ApiProxyMethod.h"
#include "PasswordKit/ApiProxyMethodExecuter/ApiProxyMethodExecuter.h"

#include "ApiProxy.h"

using namespace PasswordKit;
using namespace PasswordLogicApiInfo;

namespace {

	template <class T>
	void RegisterMethod(const Tools::ISerializeFactory& factory, PasswordLogic::IPasswordApi* api, std::map<std::string, std::unique_ptr<IApiProxyMethod>>& methods)
	{
		methods.emplace(T::NAME, std::make_unique<ApiProxyMethod<T, ApiProxyMethodExecuter<T>>>(factory, ApiProxyMethodExecuter<T>(api)));
	}

}


ApiProxy::ApiProxy(std::unique_ptr<PasswordLogic::IPasswordApi>&& passwordApi, std::unique_ptr<Tools::ISerializeFactory>&& serializeFactory)
	: m_passwordApi(std::move(passwordApi))
	, m_serializeFactory(std::move(serializeFactory))
{
	m_apiMethods = CreateApiProxyMethods();
}

ApiProxy::~ApiProxy() = default;

std::string ApiProxy::HandleMessage(const std::string& message)
{
	const auto [name, deserializer]	= ParseMessage(message);
	const auto [error, serializer]	= Execute(name, deserializer);

	return CreateMessage(name, error, serializer);
}

std::map<std::string, std::unique_ptr<IApiProxyMethod>> ApiProxy::CreateApiProxyMethods() const
{
	std::map<std::string, std::unique_ptr<IApiProxyMethod>> methods;

	RegisterMethod<SetMainPasswordMethodInfo>(*m_serializeFactory, m_passwordApi.get(), methods);

	return methods;
}

std::pair<std::string, std::shared_ptr<Tools::IDeserializer>> ApiProxy::ParseMessage(const std::string& message) const
{
	/// todo split on name and method parameters
	return std::pair<std::string, std::shared_ptr<Tools::IDeserializer>>();
}

std::string ApiProxy::CreateMessage(const std::string& name, const std::string& error, const std::shared_ptr<Tools::ISerializer>& answer) const
{
	/// todo join name, error, and answer
	return std::string();
}

std::pair<std::string, std::shared_ptr<Tools::ISerializer>> ApiProxy::Execute(const std::string& name, const std::shared_ptr<Tools::IDeserializer>& parameters) const
{
	/// todo find method by name, and execute it
	return std::pair<std::string, std::shared_ptr<Tools::ISerializer>>();
}
