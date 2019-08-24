#include <functional>
#include <vector>

#include <QCoreApplication>

#include "Tools/Same/Same.h"

#include "ApplicationController/ApplicationsSettings/ApplicationSettings.h"
#include "ApplicationController/Interfaces/IApplicationSettings.h"

#include "Interfaces/ICommandLineParser.h"

#include "CommandLineParserQt/CommandLineParserQt.h"

#include "Mediator.h"

using namespace PasswordKit;
using namespace Controller;

struct Mediator::Impl
{
	Impl()
		: commandLineParser(std::make_unique<CommandLineParserQt>())
	{
	}

	void FillPath(std::map<std::string, Tools::Same>& values)
	{
		const auto it = values.find(IApplicationSettings::KEY_DATABASE_PATH);

		if (it != values.end())
			return;

		values[IApplicationSettings::KEY_DATABASE_PATH] = commandLineParser->GetCurretDir();
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

std::unique_ptr<Controller::IApplicationSettings> Mediator::GetApplicationSettings() const
{
	m_impl->commandLineParser->Parse();

	std::map<std::string, Tools::Same> values;

	for (const auto& [key, getter] : m_impl->getters)
		if (m_impl->commandLineParser->Contains(key))
			values[key] = getter();

	m_impl->FillPath(values);

	return std::make_unique<ApplicationSettings>(values);
}

void Mediator::AddCommandLineOptions()
{
	m_impl->commandLineParser->AddHelp();

	m_impl->commandLineParser->AddOption(IApplicationSettings::KEY_ACTION, IApplicationSettings::DESCRIPTION_ACTION);
	m_impl->getters.push_back(std::make_pair(IApplicationSettings::KEY_ACTION, std::bind(&ICommandLineParser::GetString, std::cref(m_impl->commandLineParser), IApplicationSettings::KEY_ACTION)));

	m_impl->commandLineParser->AddOption(IApplicationSettings::KEY_MASTER_PASSWORD, IApplicationSettings::DESCRIPTION_MASTER_PASSWORD);
	m_impl->getters.push_back(std::make_pair(IApplicationSettings::KEY_MASTER_PASSWORD, std::bind(&ICommandLineParser::GetString, std::cref(m_impl->commandLineParser), IApplicationSettings::KEY_MASTER_PASSWORD)));

	m_impl->commandLineParser->AddOption(IApplicationSettings::KEY_DATABASE_PATH, IApplicationSettings::DESCRIPTION_KEY_DATABASE_PATH);
	m_impl->getters.push_back(std::make_pair(IApplicationSettings::KEY_DATABASE_PATH, std::bind(&ICommandLineParser::GetString, std::cref(m_impl->commandLineParser), IApplicationSettings::KEY_DATABASE_PATH)));
}
