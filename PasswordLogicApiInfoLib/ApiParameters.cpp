#include "ApiParameters.h"

using namespace PasswordLogicApiInfo;

namespace {

	const std::string KEY_PASSWORD		= "Password";
	const std::string KEY_NEW_PASSWORD	= "NewPassword";

}

void SetMainPasswordMethodInfo::Serialize(const SetMainPasswordMethodInfo::InputParameters& value, const std::shared_ptr<Tools::ISerializer>& serializer)
{
	serializer->AddString(KEY_PASSWORD		, value.password);
	serializer->AddString(KEY_NEW_PASSWORD	, value.newPassword);
}

void SetMainPasswordMethodInfo::Dserialize(SetMainPasswordMethodInfo::InputParameters& value, const std::shared_ptr<Tools::IDeserializer>& deserializer)
{
	value.password		= deserializer->GetString(KEY_PASSWORD);
	value.newPassword	= deserializer->GetString(KEY_NEW_PASSWORD);
}

void SetMainPasswordMethodInfo::Serialize(const SetMainPasswordMethodInfo::OutputParameters& value, const std::shared_ptr<Tools::ISerializer>& serializer)
{
}

void SetMainPasswordMethodInfo::Dserialize(SetMainPasswordMethodInfo::OutputParameters& value, const std::shared_ptr<Tools::IDeserializer>& deserializer)
{
}
