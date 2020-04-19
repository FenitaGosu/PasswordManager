#include "JsonSerializeFactory.h"
#include "JsonDeserializer.h"
#include "JsonSerializer.h"

using namespace JsonTools;

JsonSerializeFactory::JsonSerializeFactory(std::function<std::shared_ptr<IReaderJson>(const std::string&)> jsonReaderCreator, std::function<std::shared_ptr<IWriterJson>()> jsonWriterCreator)
	: m_jsonReaderCreator(jsonReaderCreator)
	, m_jsonWriterCreator(jsonWriterCreator)
{
}

std::shared_ptr<Tools::IDeserializer> JsonSerializeFactory::CreateDeserializer(const std::string& str) const
{
	return std::make_shared<JsonDeserializer>(m_jsonReaderCreator(str));
}

std::shared_ptr<Tools::ISerializer> JsonSerializeFactory::CreateSerializer() const
{
	return std::make_shared<JsonSerializer>(m_jsonWriterCreator());
}
