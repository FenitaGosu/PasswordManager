#include <cassert>

#include <QFile>

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
}

void Application::ConfigureStyleSheet()
{
	Q_INIT_RESOURCE(PasswordKit);
	setStyleSheet(styleSheet() + LoadStyle(STYLE_PATH));
}
