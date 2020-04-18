#pragma once

#include <memory>

#include "PasswordKit/Interfaces/IApplicationSettings.h"
#include "PasswordKit/Interfaces/IDataStream.h"
#include "PasswordKit/Interfaces/IApiProxy.h"

namespace PasswordKit {

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
