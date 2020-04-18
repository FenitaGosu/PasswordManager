#pragma once

#include <string>

#include "ToolsLib/Serialize/ISerializer.h"
#include "ToolsLib/Serialize/IDeserializer.h"

namespace Proxy {

	class IApiProxyMethod
	{
	public:
		virtual ~IApiProxyMethod() = default;

		virtual const std::string&					GetName()														const noexcept = 0;
		virtual std::shared_ptr<Tools::ISerializer>	Do(const std::shared_ptr<Tools::IDeserializer>& deserializer)	const = 0;
	};

}
