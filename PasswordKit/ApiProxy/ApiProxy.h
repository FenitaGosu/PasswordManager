#pragma once

#include <map>

#include "ToolsLib/Serialize/ISerializeFactory.h"

#include "PasswordLogicLib/PasswordApi/PasswordApi.h"

#include "PasswordKit/Interfaces/IApiProxy.h"
#include "PasswordKit/Interfaces/IApiProxyMethod.h"

namespace PasswordKit {

	class ApiProxy : public IApiProxy
	{
	public:
		ApiProxy(std::unique_ptr<PasswordLogic::IPasswordApi>&& passwordApi, std::unique_ptr<Tools::ISerializeFactory>&& serializeFactory);
		~ApiProxy();

		std::string HandleMessage(const std::string& message) override;

	private:
		std::map<std::string, std::unique_ptr<IApiProxyMethod>> CreateApiProxyMethods() const;

		std::pair<std::string, std::shared_ptr<Tools::IDeserializer>> ParseMessage(const std::string& message) const;
		std::string CreateMessage(const std::string& name, const std::string& error, const std::shared_ptr<Tools::ISerializer>& answer) const;

		std::pair<std::string, std::shared_ptr<Tools::ISerializer>> Execute(const std::string& name, const std::shared_ptr<Tools::IDeserializer>& parameters) const;

	private:
		std::unique_ptr<PasswordLogic::IPasswordApi>					m_passwordApi;
		std::unique_ptr<Tools::ISerializeFactory>						m_serializeFactory;
		std::map<std::string, std::unique_ptr<IApiProxyMethod>>			m_apiMethods;
	};

}
