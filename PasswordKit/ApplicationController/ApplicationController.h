#pragma once

#include <memory>

#include "ApiProxyLib/Interfaces/IApiProxy.h"

#include "PasswordLogicLib/Interfaces/IPasswordApi.h"

#include "PasswordKit/Interfaces/IApplicationSettings.h"
#include "PasswordKit/Interfaces/IDataStream.h"


namespace PasswordKit {

	class ApplicationController
	{
	public:
		void Setup(std::unique_ptr<Tools::ISerializeFactory>&& serializeFactory, std::unique_ptr<PasswordLogic::IPasswordApi>&& api, std::unique_ptr<IDataStream>&& dataStream);
		void Run(std::unique_ptr<IApplicationSettings>&& settings);
	
	private:
		void RunActionLoop();
		void RegisterMethods();

	private:
		std::unique_ptr<Tools::ISerializeFactory>		m_serializeFactory;
		std::unique_ptr<PasswordLogic::IPasswordApi>	m_api;
		std::unique_ptr<IDataStream>					m_dataStream;
		std::unique_ptr<Proxy::IApiProxy>				m_proxyApi;
	};

}
