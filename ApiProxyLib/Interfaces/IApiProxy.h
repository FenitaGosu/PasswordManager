#pragma once

#include <memory>
#include <string>

#include "IApiProxyMethod.h"

namespace Proxy {

	class IApiProxy
	{
	public:
		virtual ~IApiProxy() = default;

		virtual std::string HandleMessage(const std::string& message) = 0;

		virtual void RegisterMethod(std::unique_ptr<IApiProxyMethod>&& method) = 0;
	};

}
