#pragma once

#include <memory>

#include "JsonToolsLib/Interfaces/IReaderJson.h"

namespace JsonTools {

class ReaderJson : public IReaderJson
{
public:
	ReaderJson(const std::string& jsonStr);
	~ReaderJson();

public:
	bool GetBool(const std::string& key, const bool defaultValue = false) const override;
	double GetDouble(const std::string& key, const double defaultValue = 0.) const override;
	int GetInt(const std::string& key, const int defaultValue = 0.) const override;
	std::string GetString(const std::string& key, const std::string& defaultValue = std::string()) const override;
	std::shared_ptr<IReaderJson> GetObject(const std::string& key) const override;

	bool IsContains(const std::string& key) const override;
	bool IsEmpty() const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;

private:
	ReaderJson(std::unique_ptr<Impl>&& impl);
};

}
