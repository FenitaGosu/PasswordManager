#include <string>

#include <QApplication>
#include <QFile>

#include "LoggingLib/Log.h"

#include "MainWindow/MainWindow.h"

#include "Api/Api.h"

namespace {
	const std::string LOG_FILE		= "PasswordUiLog.txt";
	const std::string STYLE_FILE	= ":/style.qss";

	void LoadStyle(QApplication& app)
	{
		QFile styleFile(QString::fromStdString(STYLE_FILE));
		styleFile.open(QFile::ReadOnly);

		app.setStyleSheet(styleFile.readAll());
	}
}

int main(int argc, char* argv[])
{
	try
	{
		LOG_INIT(Logging::LogFactory::CreateFileLog(LOG_FILE));

		LOG.Write("Ui aplication started.");

		QApplication app(argc, argv);

		LoadStyle(app);

		MainWindow w;

		w.show();

		return app.exec();
	}
	catch (std::exception& exp)
	{
		LOG.Write("Ui aplication failed with error: [%s].", exp.what());

		return EXIT_FAILURE;
	}
}
