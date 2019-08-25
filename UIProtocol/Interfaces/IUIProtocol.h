#pragma once

#include <string>

namespace UIProtocol {

enum class ProtocolType;

class IUIProtocol
{
public:
	inline static const std::string CHECK_DATA_MESSAGE	= "CheckData";

public:
	virtual ~IUIProtocol() = default;

	virtual const ProtocolType GetProtocolType() const noexcept = 0;

	virtual const std::string& GetMessage() const noexcept = 0;

	virtual std::string SendMessage(const std::string& typeMessage, const std::string& message) const = 0;

	virtual void SendResultMessage(const std::string& message) = 0;
};

}
