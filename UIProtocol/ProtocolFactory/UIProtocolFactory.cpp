#include "UIProtocolFactory.h"
#include "UIProtocol/Interfaces/IUIProtocolClient.h"

#include "UIProtocolFactory.h"

using namespace UIProtocol;

UIProtocolFactory::UIProtocolFactory(const UIProtocol::ProtocolType type, const std::function<std::unique_ptr<IUIProtocolClient>()> creator)
	: m_ptorocolType(type)
	, m_creator(creator)
{
}

UIProtocol::ProtocolType UIProtocolFactory::GetProtocolType() const
{
	return m_ptorocolType;
}

std::unique_ptr<IUIProtocolClient> UIProtocolFactory::CreateProtorol() const
{
	return m_creator();
}
