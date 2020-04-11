#include "ToolsLib/StringFormat/StringFormat.h"

#include "ApiProxy.h"

using namespace PasswordKit;

ApiProxy::ApiProxy(std::unique_ptr<PasswordLogic::IPasswordApi>&& passwordApi)
	: m_passwordApi(std::move(passwordApi))
{
}

std::string ApiProxy::HandleMessage(const std::string& message)
{ 
	/// @todo parse message, call api function, create result message, return message
	return Tools::StringFormat::Format("Handle message: [%s]", message.c_str());
}
