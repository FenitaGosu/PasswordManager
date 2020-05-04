#include <stdexcept>

#include <QProcess>

#include "QtProcessExecuter.h"

#include "ToolsLib/StringFormat/StringFormat.h"

using namespace ProcessExecuter;

QtProcessExecuter::QtProcessExecuter()
	: m_process(std::make_unique<QProcess>())
{
}

QtProcessExecuter::~QtProcessExecuter()
{
	StopProcess();
}

void QtProcessExecuter::RunProcess(const std::string& path, const std::vector<std::string>& arguments)
{
	QStringList argumentsList;

	for (const std::string& argument : arguments)
		argumentsList << QString::fromStdString(argument);

	m_process->start(QString::fromStdString(path), argumentsList, QProcess::Unbuffered | QProcess::ReadWrite);


	if (!m_process->waitForStarted())
		throw std::runtime_error(Tools::StringFormat::Format("Failed to start the process with error: %s.", m_process->errorString().toStdString().c_str()));
}

void QtProcessExecuter::StopProcess()
{
	if (IsRunning())
	{
		m_process->close();
		m_process->waitForFinished();
	}
}

bool QtProcessExecuter::IsRunning() const
{
	return m_process->state() == QProcess::Running;
}

void QtProcessExecuter::WriteToStandartInput(const std::string& data)
{
	m_process->write(QByteArray::fromStdString(data));
	m_process->waitForBytesWritten();
}

std::string QtProcessExecuter::ReadFromStandartOutput()
{
	m_process->waitForReadyRead();
	return m_process->readAllStandardOutput().toStdString();
}
