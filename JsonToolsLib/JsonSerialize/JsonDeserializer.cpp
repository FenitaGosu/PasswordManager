#include "JsonDeserializer.h"

using namespace JsonTools;

JsonDeserializer::JsonDeserializer(const std::shared_ptr<IReaderJson>& jsonReader)
	: m_jsonReader(jsonReader)
{
}

bool JsonDeserializer::GetBool(const std::string& key, const bool defaultValue) const
{
	return m_jsonReader->GetBool(key, defaultValue);
}

double JsonDeserializer::GetDouble(const std::string& key, const double defaultValue) const
{
	return m_jsonReader->GetDouble(key, defaultValue);
}

int JsonDeserializer::GetInt(const std::string& key, const int defaultValue) const
{
	return m_jsonReader->GetInt(key, defaultValue);
}

std::string JsonDeserializer::GetString(const std::string& key, const std::string& defaultValue) const
{
	return m_jsonReader->GetString(key, defaultValue);
}

std::shared_ptr<Tools::IDeserializer> JsonTools::JsonDeserializer::GetObject(const std::string& key) const
{
	return std::make_shared<JsonDeserializer>(m_jsonReader->GetObject(key));
}

bool JsonDeserializer::IsContains(const std::string& key) const
{
	return m_jsonReader->IsContains(key);
}

bool JsonTools::JsonDeserializer::IsEmpty() const
{
	return m_jsonReader->IsEmpty();
}
