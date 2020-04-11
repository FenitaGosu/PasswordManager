#pragma once

#include "PasswordLogicLib/PasswordApi/PasswordApi.h"

#include "ApplicationControllerLib/Interfaces/IApiProxy.h"

namespace PasswordKit {

	class ApiProxy : public Controller::IApiProxy
	{
	public:
		ApiProxy(std::unique_ptr<PasswordLogic::IPasswordApi>&& passwordApi);

		std::string HandleMessage(const std::string& message);

	private:
		std::unique_ptr<PasswordLogic::IPasswordApi> m_passwordApi;
	};

}
