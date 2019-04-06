#pragma once

#include <map>
#include <string>

#include "Tools/Same/Same.h"

namespace PasswordKit {

class ICommandLineParser
{
public:
	virtual ~ICommandLineParser() = default;

	virtual void AddHelp() = 0;

	virtual void AddInt(const std::string& name, const std::string& description, int defaultValue = 0) = 0;
	virtual void AddSting(const std::string& name, const std::string& description, const std::string& defaultValue = std::string() = 0;

	virtual std::map<std::string, Tools::Same> GetValues() const = 0
};

}