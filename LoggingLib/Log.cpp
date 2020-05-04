#include <chrono>
#include <sstream> 

#include "ToolsLib/StringFormat/StringFormat.h"

#include "Log.h"
#include "LogFactory/LogFactory.h"

using namespace Logging;

std::shared_ptr<ILog> Log::m_logger = LogFactory::CreateEmptyLog();

void Log::Init(const std::shared_ptr<ILog>& logger)
{
	Log::m_logger = logger;
}

std::string Log::GetCurrentTime()
{
	std::time_t t = std::time(nullptr);

	char mbstr[100];
	std::strftime(mbstr, sizeof(mbstr), "%A %c", std::localtime(&t));

	return mbstr;
}

Log::Log(const std::string& file, const int line, const std::string& timeAndDate)
	: m_logHeader(Tools::StringFormat::Format("Path:[%s]; Line:[%i]; Time:[%s]; ", file.c_str(), line, timeAndDate.c_str()))
{
}

void Log::Write(const std::string& message)
{
	m_logger->Write(m_logHeader + Tools::StringFormat::Format(message));
}

void Log::Write(const std::string& message, const std::string& arg0)
{
	m_logger->Write(m_logHeader + Tools::StringFormat::Format(message, arg0.c_str()));
}

void Log::Write(const std::string& message, const std::string& arg0, const std::string& arg1)
{
	m_logger->Write(m_logHeader + Tools::StringFormat::Format(message, arg0.c_str(), arg1.c_str()));
}

void Log::Write(const std::string& message, const std::string& arg0, const std::string& arg1, const std::string& arg2)
{
	m_logger->Write(m_logHeader + Tools::StringFormat::Format(message, arg0.c_str(), arg1.c_str(), arg2.c_str()));
}
