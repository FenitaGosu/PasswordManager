#pragma once

#include <functional>
#include <memory>
#include <string>

#include "Interfaces/ILog.h"

namespace Logging
{
	class Log
	{
	public:
		static void Init(const std::shared_ptr<ILog>& logger);
		static std::string GetCurrentTime();

	public:
		Log(const std::string& file, const int line, const std::string& timeAndDate);

		void Write(const std::string& message);
		void Write(const std::string& message, const std::string& arg0);
		void Write(const std::string& message, const std::string& arg0, const std::string& arg1);
		void Write(const std::string& message, const std::string& arg0, const std::string& arg1, const std::string& arg2);

	private:
		static std::shared_ptr<ILog> m_logger;
		const std::string m_logHeader;
	};
}

#define LOG_INIT(LOGGER)	Logging::Log::Init(LOGGER)
#define LOG					Logging::Log(std::string(__FILE__), __LINE__, Logging::Log::GetCurrentTime())
