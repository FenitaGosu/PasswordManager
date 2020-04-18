#include "ApiProxy.h"

using namespace Proxy;

ApiProxy::ApiProxy(const Tools::ISerializeFactory& serializeFactory)
	: m_serializeFactory(serializeFactory)
{
}

ApiProxy::~ApiProxy() = default;

std::string ApiProxy::HandleMessage(const std::string& message)
{
	const auto [name, deserializer]	= ParseMessage(message);
	const auto [error, serializer]	= Execute(name, deserializer);

	return CreateMessage(name, error, serializer);
}

void ApiProxy::ApiProxy::RegisterMethod(std::unique_ptr<IApiProxyMethod>&& method)
{
	auto name = method->GetName();
	m_apiMethods.emplace(name, std::move(method));
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
