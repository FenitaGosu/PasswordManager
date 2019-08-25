#include "UIProtocol/Interfaces/IUIProtocolClient.h"

#include "UIProtocolFactory.h"

using namespace UIProtocol;

UIProtocolFactory::UIProtocolFactory(std::function<std::unique_ptr<IUIProtocolClient>()> creator)
	: m_creator(creator)
{
}

std::unique_ptr<IUIProtocolClient> UIProtocolFactory::CreateProtorol() const
{
	return m_creator();
}
