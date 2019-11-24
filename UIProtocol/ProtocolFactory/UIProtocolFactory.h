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
	UIProtocolFactory(const UIProtocol::ProtocolType type, const std::function<std::unique_ptr<IUIProtocolClient>()> creator);

	UIProtocol::ProtocolType GetProtocolType() const;
	std::unique_ptr<IUIProtocolClient> CreateProtorol() const;

private:
	UIProtocol::ProtocolType m_ptorocolType;
	const std::function<std::unique_ptr<IUIProtocolClient>()> m_creator;
};

}
