#pragma once

#include "JsonToolsLib/Interfaces/IReaderJson.h"

#include "ToolsLib/Serialize/IDeserializer.h"

namespace JsonTools {

	class JsonDeserializer : public Tools::IDeserializer
	{
	public:
		JsonDeserializer(const std::shared_ptr<IReaderJson>& jsonReader);

		bool									GetBool(const std::string& key, const bool defaultValue = false) const override;
		double									GetDouble(const std::string& key, const double defaultValue = 0.) const override;
		int										GetInt(const std::string& key, const int defaultValue = 0.) const override;
		std::string								GetString(const std::string& key, const std::string& defaultValue = std::string()) const override;
		std::shared_ptr<Tools::IDeserializer>	GetObject(const std::string& key) const override;

		bool IsContains(const std::string& key) const override;
		bool IsEmpty() const override;

	private:
		std::shared_ptr<IReaderJson> m_jsonReader;
	};

}
