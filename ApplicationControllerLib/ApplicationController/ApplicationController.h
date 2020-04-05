#pragma once

#include <memory>

#include "PasswordLogicLib/Interfaces/IPasswordApi.h"

#include "ApplicationControllerLib/Interfaces/IApplicationSettings.h"
#include "ApplicationControllerLib/Interfaces/IDataStream.h"


namespace Controller {

	class ApplicationController
	{
	public:
		ApplicationController();
		~ApplicationController();
	
		void Setup(std::unique_ptr<PasswordLogic::IPasswordApi>&& passwordApi, std::unique_ptr<IDataStream>&& dataStream);
	
		void Run(std::unique_ptr<IApplicationSettings>&& settings);
	
	private:
		void RunActionLoop();
	
	private:
		struct Impl;
		std::unique_ptr<Impl>							m_impl;
		std::unique_ptr<PasswordLogic::IPasswordApi>	m_passwordApi;
		std::unique_ptr<IDataStream>					m_dataStream;
	};

}
