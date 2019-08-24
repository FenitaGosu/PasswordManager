#pragma once

#include <string>

namespace PasswordUI {

enum class ProtocolType;

class IUIProtocolDataTransfer
{
public:
	virtual ~IUIProtocolDataTransfer() = default;

	virtual const ProtocolType GetProtocolType() const noexcept = 0;

	virtual const std::string& GetMessage() const noexcept = 0;
	virtual std::string SendMessage(const std::string&) const = 0;
};

}
