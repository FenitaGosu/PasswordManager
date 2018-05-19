#pragma once

#include <memory>

#include <QApplication>

namespace PasswordKit {

class IApplicatonSettings;

class Application: public QApplication
{
	Q_OBJECT

public:
	Application(int& argc, char** argv);
	void СonfiguringApplicationSettings(std::unique_ptr<IApplicatonSettings>&& settings);

private:
	void ConfigureStyleSheet();
};

}

#define GetApp (static_cast<App::Application*>(QApplication::instance()))
