#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>

#include "UIProtocol/ProtocolFactory/UIProtocolFactory.h"
#include "UIProtocol/Protocol/Protocol.h"

TEST(UIProtocolTest, FactoryTest)
{
	std::unique_ptr<UIProtocol::UIProtocolFactory> uiProtocolFactory = std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, [](){ return std::make_unique<UIProtocol::Protocol>(); });

	ASSERT_NE(uiProtocolFactory->CreateProtorol(), nullptr);
}

TEST(UIProtocolTest, TypeTest)
{
	const auto protocol = std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, [](){ return std::make_unique<UIProtocol::Protocol>(); })->CreateProtorol();

	protocol->SetType(UIProtocol::ProtocolType::JSON);
	
	ASSERT_EQ(protocol->ToUIProtocol().GetProtocolType(), UIProtocol::ProtocolType::JSON);
}

TEST(UIProtocolTest, MessageTest)
{
	const auto protocol = std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, [](){ return std::make_unique<UIProtocol::Protocol>(); })->CreateProtorol();

	protocol->SetMessage("Hellow world!");
	
	ASSERT_EQ(protocol->ToUIProtocol().GetMessage(), "Hellow world!");
}

TEST(UIProtocolTest, HandlerTest)
{
	const auto protocol = std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, [](){ return std::make_unique<UIProtocol::Protocol>(); })->CreateProtorol();
	
	ASSERT_NO_THROW(protocol->AddMessageHandler(std::make_pair("MyHandler", [](const std::string& message) { return message; })));
}

TEST(UIProtocolTest, HandlerAlredyExistTest)
{
	const auto protocol = std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, [](){ return std::make_unique<UIProtocol::Protocol>(); })->CreateProtorol();
	protocol->AddMessageHandler(std::make_pair("MyHandler", [](const std::string& message) { return message; }));

	ASSERT_ANY_THROW(protocol->AddMessageHandler(std::make_pair("MyHandler", [](const std::string& message) { return message; })));
}

TEST(UIProtocolTest, HandlerExistTest)
{
	const auto protocol = std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, [](){ return std::make_unique<UIProtocol::Protocol>(); })->CreateProtorol();

	protocol->AddMessageHandler(std::make_pair("MyHandler", [](const std::string& message) { return message; }));

	ASSERT_NO_THROW(protocol->ToUIProtocol().SendMessage("MyHandler", "Hellow world!"));
}

TEST(UIProtocolTest, HandlerNotExistTest)
{
	const auto protocol = std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, [](){ return std::make_unique<UIProtocol::Protocol>(); })->CreateProtorol();

	protocol->AddMessageHandler(std::make_pair("MyHandler", [](const std::string& message) { return message; }));

	ASSERT_ANY_THROW(protocol->ToUIProtocol().SendMessage("TEST", "Hellow world!"));
}

TEST(UIProtocolTest, ResultTest)
{
	const auto protocol = std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, [](){ return std::make_unique<UIProtocol::Protocol>(); })->CreateProtorol();

	protocol->ToUIProtocol().SendResultMessage("Hellow world!");

	ASSERT_EQ(protocol->GetResult(), "Hellow world!");
}
