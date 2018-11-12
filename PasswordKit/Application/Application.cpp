#include <cassert>

#include <QFile>
#include <QDir>
#include <QStandardPaths>
#include <QMainWindow>

#include "Interfaces/IApplicationSettings.h"

#include "Application.h"

namespace {

const QString STYLE_PATH = ":/resources/theme/style.qss";

QString LoadStyle(const QString& file)
{
	QFile style(file);
	bool isOpen = style.open(QFile::ReadOnly);
	assert(isOpen);
	return style.readAll();
}

}

using namespace PasswordKit;

Application::Application(int& argc, char** argv)
	: QApplication(argc, argv)
{
}

void Application::СonfiguringApplicationSettings(std::unique_ptr<IApplicatonSettings>&& settings)
{
	setOrganizationName(settings->GetOrganizationName());
	setApplicationName(settings->GetApplicationName());

	ConfigureStyleSheet();
	CreateApplicationPath();
}

void Application::SetMainWindow(QMainWindow* mainWindow)
{
	m_window = mainWindow;
}

QMainWindow* Application::GetMainWindow() const noexcept
{
	return m_window;
}

QString Application::GetApplicarionPath() const noexcept
{
	return m_applicationPath;
}

void Application::ConfigureStyleSheet()
{
	Q_INIT_RESOURCE(PasswordKit);
	setStyleSheet(styleSheet() + LoadStyle(STYLE_PATH));
}

void Application::CreateApplicationPath()
{
	QDir folder(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
	folder.mkpath(QApplication::applicationName());
	m_applicationPath = folder.path() += "/" + QApplication::applicationName();
}
