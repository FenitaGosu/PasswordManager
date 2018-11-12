#pragma once

#include <memory>

#include <QString>
#include <QApplication>

class QMainWindow;

namespace PasswordKit {

class IApplicatonSettings;

class Application: public QApplication
{
	Q_OBJECT

public:
	Application(int& argc, char** argv);
	void СonfiguringApplicationSettings(std::unique_ptr<IApplicatonSettings>&& settings);
	void SetMainWindow(QMainWindow *mainWindow);

	QMainWindow* GetMainWindow() const noexcept;
	QString GetApplicarionPath() const noexcept;

private:
	void ConfigureStyleSheet();
	void CreateApplicationPath();

private:
	QMainWindow* m_window;
	QString m_applicationPath;
};

}

#define GetApp (static_cast<PasswordKit::Application*>(QApplication::instance()))
