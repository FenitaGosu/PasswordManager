#pragma once

#include "LoggingLib/Interfaces/ILog.h"

namespace Logging
{
	class EmptyLog : public ILog
	{
	public:
		void Write(const std::string& message) override;
	};
}
