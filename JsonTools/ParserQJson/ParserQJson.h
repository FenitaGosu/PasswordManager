#pragma once

#include <memory>

#include "Interfaces/IParserJson.h"

class QJsonObject;

namespace JsonTools {

/**
 * Qt implementation of the interface IParserJson.
 */
class ParserQJson : public IParserJson
{
public:
	ParserQJson(const std::string& filePath);
	~ParserQJson();

private:
	ParserQJson(QJsonObject&& obj);

public:
	bool GetBool(const std::string& key, const bool defaultValue = false) const override;
	double GetDouble(const std::string& key, const double defaultValue = 0.) const override;
	int GetInt(const std::string& key, const int defaultValue = 0.) const override;
	std::string GetString(const std::string& key, const std::string& defaultValue = std::string()) const override;
	std::shared_ptr<IParserJson> GetObject(const std::string& key) const override;

	bool IsContains(const std::string& key) const override;
	bool IsEmpty() const override;

private:
	std::shared_ptr<QJsonObject> m_obj;
};

}
