#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>

#include "Application/Application.h"
#include "ApplicationSettings/ApplicatonSettingsJsonImpl.h"

#include "MainWindow.h"

int main(int argc, char *argv[])
{
	try
	{
		PasswordKit::Application app(argc, argv);
		app.СonfiguringApplicationSettings(std::make_unique<PasswordKit::ApplicatonSettingsJsonImpl>());

		PasswordKit::MainWindow w;
		w.setWindowTitle(app.applicationName());
		w.show();

		return app.exec();
	}
	catch(std::exception& exp)
	{
		std::cerr << exp.what();
		return EXIT_FAILURE;
	}
}
