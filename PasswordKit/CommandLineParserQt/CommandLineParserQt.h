#pragma once

#include <memory>
#include <string>

#include "ApplicationControllerLib/Interfaces/ICommandLineParser.h"

class QCoreApplication;

namespace PasswordKit {

class CommandLineParserQt : public Controller::ICommandLineParser
{
public:
	CommandLineParserQt();

	void AddHelp() override;
	void AddOption(const std::string& name, const std::string& description) override;

	void Parse() override;

	std::string GetCurrentDir() const override;

	bool Contains(const std::string& name) const override;

	int GetInt(const std::string& name) const override;
	std::string GetString(const std::string& name) const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
