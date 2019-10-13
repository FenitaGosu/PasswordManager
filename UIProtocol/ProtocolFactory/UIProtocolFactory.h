#pragma once

#include <map>
#include <functional>
#include <memory>

namespace UIProtocol {

class IUIProtocolClient;
enum class ProtocolType;

class UIProtocolFactory
{
public:
	UIProtocolFactory(std::function<std::pair<UIProtocol::ProtocolType, std::unique_ptr<IUIProtocolClient>>()> creator);

	std::pair<UIProtocol::ProtocolType, std::unique_ptr<IUIProtocolClient>> CreateProtorol() const;

private:
	std::function <std::pair<UIProtocol::ProtocolType, std::unique_ptr<IUIProtocolClient>>()> m_creator;
};

}
