#include <string>

#include <QApplication>

#include "LoggingLib/Log.h"

#include "MainWindow/MainWindow.h"

namespace {
	const std::string LOG_FILE = "PasswordUiLog.txt";
}

int main(int argc, char* argv[])
{
	try
	{
		LOG_INIT(Logging::LogFactory::CreateFileLog(LOG_FILE));

		LOG.Write("Ui aplication started.");

		QApplication a(argc, argv);

		MainWindow w;

		w.show();

		return a.exec();
	}
	catch (std::exception& exp)
	{
		LOG.Write("Ui aplication failed with error: [%s].", exp.what());

		return EXIT_FAILURE;
	}
}
