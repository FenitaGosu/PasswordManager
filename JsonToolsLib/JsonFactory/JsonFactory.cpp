#include "JsonToolsLib/Interfaces/IWriterJson.h"
#include "JsonToolsLib/Interfaces/IReaderJson.h"

#include "JsonFactory.h"

using namespace JsonTools;

JsonFactory::JsonFactory(std::function<std::unique_ptr<IReaderJson>(const std::string&)> readerCreator, std::function<std::unique_ptr<IWriterJson>()> writerCreator)
	: m_readerCreator(readerCreator)
	, m_writerCreator(writerCreator)
{
}

std::unique_ptr<IReaderJson> JsonFactory::CreateReader(const std::string& str) const
{
	return m_readerCreator(str);
}

std::unique_ptr<IWriterJson> JsonFactory::CreateWriter() const
{
	return m_writerCreator();
}
