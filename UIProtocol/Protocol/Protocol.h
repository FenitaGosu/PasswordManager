#pragma once

#include <memory>

#include "UIProtocol/Interfaces/IUIProtocol.h"
#include "UIProtocol/Interfaces/IUIProtocolClient.h"
#include "UIProtocol/Enums/ProtocolType.h"

namespace UIProtocol {

class Protocol
	: public IUIProtocol
	, public IUIProtocolClient
{
public:
	Protocol();
	~Protocol();

public:
	const ProtocolType GetProtocolType() const noexcept override;
	const std::string& GetMessage() const noexcept override;
	std::string SendMessage(const std::string& typeMessage, const std::string& message) const override;
	void SendResultMessage(const std::string& message) override;

public:
	IUIProtocol& ToUIProtocol() override;
	void SetType(ProtocolType type) override;
	void SetMessage(const std::string& message)override;
	void AddMessageHandler(const MessageHandler& handler) override;
	const std::string& GetResult() const noexcept override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
