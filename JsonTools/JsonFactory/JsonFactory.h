#pragma once

#include <map>
#include <functional>
#include <memory>

namespace JsonTools {

class IReaderJson;
class IWriterJson;

class JsonFactory
{
public:
	JsonFactory(std::function<std::unique_ptr<IReaderJson>(const std::string&)> readerCreator, std::function<std::unique_ptr<IWriterJson>()> writerCreator);

	std::unique_ptr<IReaderJson> CreateReader(const std::string& str) const;
	std::unique_ptr<IWriterJson> CreateWriter() const;

private:
	std::function<std::unique_ptr<IReaderJson>(const std::string&)> m_readerCreator;
	std::function<std::unique_ptr<IWriterJson>()> m_writerCreator;
};

}
