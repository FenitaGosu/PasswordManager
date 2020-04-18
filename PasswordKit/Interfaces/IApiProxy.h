#pragma once

#include <string>

namespace PasswordKit {

	class IApiProxy
	{
	public:
		virtual ~IApiProxy() = default;

		virtual std::string HandleMessage(const std::string& message) = 0;
	};

}
