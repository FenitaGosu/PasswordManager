#pragma once

#include <string>

namespace Controller {

	class IApiProxy
	{
	public:
		virtual ~IApiProxy() = default;

		virtual std::string HandleMessage(const std::string& message) = 0;
	};

}
