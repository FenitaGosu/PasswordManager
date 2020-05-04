#include "StreamLog.h"

using namespace Logging;

StreamLog::StreamLog(std::unique_ptr<std::ostream>&& stream)
	: m_stream(std::move(stream))
{
}

StreamLog::~StreamLog() = default;

void StreamLog::Write(const std::string& message)
{
	*m_stream << message << std::endl;
}
