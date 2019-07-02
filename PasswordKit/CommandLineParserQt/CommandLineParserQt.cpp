#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QString>

#include "CommandLineParserQt.h"

using namespace PasswordKit;

struct CommandLineParserQt::Impl
{
	QCommandLineParser parser;
};

CommandLineParserQt::CommandLineParserQt()
	: m_impl(std::make_unique<Impl>())
{
}

void CommandLineParserQt::AddHelp()
{
	m_impl->parser.addHelpOption();
}

void CommandLineParserQt::AddOption(const std::string& name, const std::string& description)
{
	m_impl->parser.addOption(QCommandLineOption({ QString(QString::fromStdString(name).front()), QString::fromStdString(name)},  QString::fromStdString(description), QString::fromStdString(name)));
}

void CommandLineParserQt::Parse()
{
	m_impl->parser.process(*QCoreApplication::instance());
}

std::string CommandLineParserQt::GetCurretDir() const
{
	return QCoreApplication::applicationDirPath().toStdString();
}

bool CommandLineParserQt::Contains(const std::string& name) const
{
	return m_impl->parser.isSet(QString::fromStdString(name));
}

int CommandLineParserQt::GetInt(const std::string& name) const
{
	return m_impl->parser.value(QString::fromStdString(name)).toInt();
}

std::string CommandLineParserQt::GetString(const std::string& name) const
{
	return m_impl->parser.value(QString::fromStdString(name)).toStdString();
}
