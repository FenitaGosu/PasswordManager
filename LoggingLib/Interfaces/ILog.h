#pragma once

#include <string>

namespace Logging
{
	class ILog
	{
	public:
		~ILog() = default;

		virtual void Write(const std::string& message) = 0;
	};
}
