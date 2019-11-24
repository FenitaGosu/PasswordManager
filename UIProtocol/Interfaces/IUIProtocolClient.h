#pragma once

#include <functional>
#include <string>

#include "UIProtocol/Interfaces/IUIProtocol.h"
#include "UIProtocol/Interfaces/ProtocolDefines.h"
#include "UIProtocol/Enums/ProtocolType.h"

namespace UIProtocol {

class IUIProtocolClient
{
public:
	virtual ~IUIProtocolClient() = default;

	virtual IUIProtocol& ToUIProtocol() = 0;

	virtual void SetType(ProtocolType type) = 0;
	virtual void SetMessage(const std::string& message) = 0;
	virtual void AddMessageHandler(const MessageHandler& handler) = 0;

	virtual const std::string& GetResult() const noexcept = 0;
};

}
