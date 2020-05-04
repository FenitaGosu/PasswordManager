#pragma once

#include <memory>
#include <string>
#include <filesystem>

#include "LoggingLib/Interfaces/ILog.h"

namespace Logging
{
	class LogFactory
	{
	public:
		static std::shared_ptr<ILog> CreateEmptyLog();
		static std::shared_ptr<ILog> CreateFileLog(const std::filesystem::path& path, bool deletePreviousLog = false);
	};

}
