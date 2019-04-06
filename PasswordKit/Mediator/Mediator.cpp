#include <functional>
#include <vector>

#include <QCoreApplication>

#include "Tools/Same/Same.h"

#include "Interfaces/IApplicationSettings.h"
#include "Interfaces/ICommandLineParser.h"

#include "CommandLineParserQt/CommandLineParserQt.h"
#include "ApplicationsSettings/ApplicationSettings.h"

#include "Mediator.h"

using namespace PasswordKit;

namespace {
	const std::string KEY_ACTION = "action";
	const std::string DESCRIPTION_ACTION = "What should be done?";

	const std::string KEY_PASSWORD = "password";
	const std::string DESCRIPTION_PASSWORD = "Password string.";
}

struct Mediator::Impl
{
	Impl()	
		: commandLineParser(std::make_unique<CommandLineParserQt>())
	{
	}
	
	std::unique_ptr<ICommandLineParser> commandLineParser;
	std::vector <std::pair<std::string, std::function<Tools::Same()>>> getters;
};

Mediator::Mediator()
	: m_impl(std::make_unique<Impl>())
{
	AddCommandLineOptions();
}

Mediator::~Mediator() = default;

std::unique_ptr<IApplicationSettings> Mediator::GetApplicationSettings() const
{
	m_impl->commandLineParser->Parse();

	std::map<std::string, Tools::Same> values;

	for (const auto& getter : m_impl->getters)
		if (m_impl->commandLineParser->Contains(getter.first))
			values[getter.first] = getter.second();

	return std::make_unique<ApplicationSettings>(values);
}

void Mediator::AddCommandLineOptions()
{
	m_impl->commandLineParser->AddHelp();

	m_impl->commandLineParser->AddOption(KEY_ACTION, DESCRIPTION_ACTION);
	m_impl->getters.push_back(std::make_pair(KEY_ACTION, std::bind(&ICommandLineParser::GetInt, std::cref(m_impl->commandLineParser), KEY_ACTION)));

	m_impl->commandLineParser->AddOption(KEY_PASSWORD, DESCRIPTION_PASSWORD);
	m_impl->getters.push_back(std::make_pair(KEY_PASSWORD, std::bind(&ICommandLineParser::GetString, std::cref(m_impl->commandLineParser), KEY_PASSWORD)));
}