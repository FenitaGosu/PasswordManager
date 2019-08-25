#include "Protocol.h"

using namespace UIProtocol;

struct Protocol::Impl
{
	ProtocolType type;

	std::string message;
	std::string resultMessage;
};

Protocol::Protocol()
	: m_impl(std::make_unique<Impl>())
{
}

Protocol::~Protocol() = default;

const ProtocolType Protocol::GetProtocolType() const noexcept
{
	return m_impl->type;
}

const std::string& Protocol::GetMessage() const noexcept
{
	return m_impl->message;
}

std::string Protocol::SendMessage(const std::string& typeMessage, const std::string& message) const
{
	return std::string();
}

void Protocol::SendResultMessage(const std::string& message)
{
}

IUIProtocol& Protocol::ToUIProtocol()
{
	return *this;
}

void Protocol::SetType(ProtocolType type)
{
	m_impl->type = type;
}

void Protocol::SetMessage(const std::string& message)
{
	m_impl->message = message;
}

void Protocol::AddMessageHandler(const std::string& messageType, std::function<std::string(const std::string&)> handler)
{
}

const std::string& Protocol::GetResult() const noexcept
{
	return m_impl->resultMessage;
}
