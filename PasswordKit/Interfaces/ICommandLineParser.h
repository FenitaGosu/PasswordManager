#pragma once

#include <map>
#include <string>

namespace PasswordKit {

class ICommandLineParser
{
public:
	virtual ~ICommandLineParser() = default;

	virtual void AddHelp() = 0;
	virtual void AddOption(const std::string& name, const std::string& description) = 0;

	virtual void Parse() = 0;

	virtual std::string GetCurretDir() const = 0;

	virtual bool Contains(const std::string& key) const = 0;

	virtual int GetInt(const std::string& name) const = 0;
	virtual std::string GetString(const std::string& name) const = 0;
};

}
