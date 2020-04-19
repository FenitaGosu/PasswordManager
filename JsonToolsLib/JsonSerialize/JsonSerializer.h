#pragma once

#include "JsonToolsLib/Interfaces/IWriterJson.h"

#include "ToolsLib/Serialize/ISerializer.h"

namespace JsonTools {

	class JsonSerializer : public Tools::ISerializer
	{
	public:
		JsonSerializer(const std::shared_ptr<IWriterJson>& jsonWriter);

		void AddBool	(const std::string& key, bool value) override;
		void AddDouble	(const std::string& key, double value) override;
		void AddInt		(const std::string& key, int value) override;
		void AddString	(const std::string& key, const std::string& value) override;
		void AddObject	(const std::string& key, const std::shared_ptr<Tools::ISerializer>& object) override;

		std::string Serialize() const override;

	private:
		std::shared_ptr<IWriterJson> m_jsonWriter;
	};
}
