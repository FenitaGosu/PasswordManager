#pragma once

#include <map>

#include "ToolsLib/Serialize/ISerializeFactory.h"

#include "ApiProxyLib/Interfaces/IApiProxy.h"
#include "ApiProxyLib/Interfaces/IApiProxyMethod.h"

namespace Proxy {

	class ApiProxy : public IApiProxy
	{
	public:
		ApiProxy(const std::shared_ptr<Tools::ISerializeFactory>& serializeFactory);
		~ApiProxy();

		std::string HandleMessage(const std::string& message) override;

		void RegisterMethod(std::unique_ptr<IApiProxyMethod>&& method) override;

	private:

		std::pair<std::string, std::shared_ptr<Tools::IDeserializer>> ParseMessage(const std::string& message) const;
		std::string CreateMessage(const std::string& name, const std::string& error, const std::shared_ptr<Tools::ISerializer>& answer) const;

		std::pair<std::string, std::shared_ptr<Tools::ISerializer>> Execute(const std::string& name, const std::shared_ptr<Tools::IDeserializer>& parameters) const;

	private:
		std::shared_ptr<Tools::ISerializeFactory>				m_serializeFactory;
		std::map<std::string, std::unique_ptr<IApiProxyMethod>>	m_apiMethods;
	};

}
