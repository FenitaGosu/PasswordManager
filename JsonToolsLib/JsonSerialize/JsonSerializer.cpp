#include <stdexcept>

#include "JsonSerializer.h"

using namespace JsonTools;

JsonSerializer::JsonSerializer(const std::shared_ptr<IWriterJson>& jsonWriter)
	: m_jsonWriter(jsonWriter)
{
}

void JsonSerializer::AddBool(const std::string& key, bool value)
{
	m_jsonWriter->AddBool(key, value);
}

void JsonSerializer::AddDouble(const std::string& key, double value)
{
	m_jsonWriter->AddDouble(key, value);
}

void JsonSerializer::AddInt(const std::string& key, int value)
{
	m_jsonWriter->AddInt(key, value);
}

void JsonSerializer::AddString(const std::string& key, const std::string& value)
{
	m_jsonWriter->AddString(key, value);
}

void JsonSerializer::AddObject(const std::string& key, const std::shared_ptr<Tools::ISerializer>& object)
{
	const auto jsonSerializerObject = std::dynamic_pointer_cast<JsonSerializer>(object);

	if (!jsonSerializerObject)
		throw std::runtime_error("Object is not JsonSerializer");

	m_jsonWriter->AddObject(key, jsonSerializerObject->m_jsonWriter);
}

std::string JsonSerializer::Serialize() const
{
	return m_jsonWriter->Serialize();
}
