#pragma once

#include <map>
#include <functional>
#include <memory>

namespace UIProtocol {

class IUIProtocolClient;

class UIProtocolFactory
{
public:
	UIProtocolFactory(std::function<std::unique_ptr<IUIProtocolClient>()> creator);

	std::unique_ptr<IUIProtocolClient> CreateProtorol() const;

private:
	std::function <std::unique_ptr<IUIProtocolClient>()> m_creator;
};

}
