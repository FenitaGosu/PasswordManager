#pragma once

#include "Interfaces/ICommandLineParser.h"

namespace PasswordKit {

class CommandLineParserQt : public ICommandLineParser
{
public:
	virtual ~CommandLineParserQt() = default;

	void AddHelp() override;

	void AddInt(const std::string& name, const std::string& description, int defaultValue = 0) override;
	void AddSting(const std::string& name, const std::string& description, const std::string& defaultValue = std::string() override;

	std::map<std::string, Tools::Same> GetValues() override;
};

}