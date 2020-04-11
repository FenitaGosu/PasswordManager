#pragma once

#include <memory>

#include "ApplicationControllerLib/Interfaces/IApplicationSettings.h"
#include "ApplicationControllerLib/Interfaces/IDataStream.h"
#include "ApplicationControllerLib/Interfaces/IApiProxy.h"

namespace Controller {

	class ApplicationController
	{
	public:
		void Setup(std::unique_ptr<IApiProxy>&& passwordApi, std::unique_ptr<IDataStream>&& dataStream);	
		void Run(std::unique_ptr<IApplicationSettings>&& settings);
	
	private:
		void RunActionLoop();
	
	private:
		std::unique_ptr<IApiProxy>		m_passwordApi;
		std::unique_ptr<IDataStream>	m_dataStream;
	};

}
