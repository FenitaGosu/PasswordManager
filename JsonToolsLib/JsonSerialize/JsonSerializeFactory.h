#pragma once

#include <functional>

#include "JsonToolsLib/Interfaces/IWriterJson.h"
#include "JsonToolsLib/Interfaces/IReaderJson.h"

#include "ToolsLib/Serialize/ISerializeFactory.h"
#include "ToolsLib/Serialize/ISerializer.h"
#include "ToolsLib/Serialize/IDeserializer.h"

namespace JsonTools {

	class JsonSerializeFactory : public Tools::ISerializeFactory
	{
	public:
		JsonSerializeFactory(std::function<std::shared_ptr<IReaderJson>(const std::string&)> jsonReaderCreator, std::function<std::shared_ptr<IWriterJson>()> jsonWriterCreator);

		std::shared_ptr<Tools::IDeserializer>	CreateDeserializer(const std::string& str) const override;
		std::shared_ptr<Tools::ISerializer>		CreateSerializer() const override;

	private:
		std::function<std::shared_ptr<IReaderJson>(const std::string&)>	m_jsonReaderCreator;
		std::function<std::shared_ptr<IWriterJson>()>					m_jsonWriterCreator;
	};

}
