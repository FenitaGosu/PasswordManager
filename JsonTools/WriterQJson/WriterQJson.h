#pragma once

#include <memory>
#include <string>

#include "Interfaces/IWriterJson.h"

namespace JsonTools {

class WriterQJson : public IWriterJson
{
public:
	WriterQJson();
	~WriterQJson();

	void AddBool(const std::string& key, bool value) override;
	void AddDouble(const std::string& key, double value) override;
	void AddInt(const std::string& key, int value) override;
	void AddString(const std::string& key, const std::string& value) override;
	void AddObject(const std::string& key, const std::shared_ptr<IWriterJson>& object) override;

	std::string Serialize() const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
