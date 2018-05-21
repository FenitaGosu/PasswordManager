#pragma once

#include <memory>

#include <QPointer>
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
	void SetMainWindow(QPointer<QMainWindow> mainWindow);

	QPointer<QMainWindow> GetMainWindow() const;

private:
	void ConfigureStyleSheet();

private:
	QPointer<QMainWindow> m_window;
};

}

#define GetApp (static_cast<PasswordKit::Application*>(QApplication::instance()))
