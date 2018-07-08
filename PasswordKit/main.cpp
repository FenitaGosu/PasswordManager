#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>

#include "Application/Application.h"
#include "ApplicationSettings/ApplicatonSettingsJsonImpl.h"

#include "PasswordLogic/Interfaces/ICredentialsInspector.h"
#include "PasswordLogic/CredentialsInspector/CredentialsInspector.h"

#include "Mediator/Mediator.h"

#include "MainWindow.h"

int main(int argc, char *argv[])
{
	try
	{
		PasswordKit::Application app(argc, argv);

		app.СonfiguringApplicationSettings(std::make_unique<PasswordKit::ApplicatonSettingsJsonImpl>());

		PasswordKit::Mediator mediator(std::make_unique<PasswordLogic::CredentialsInspector>());

		if(!mediator.ShowLoginDialog())
			return EXIT_FAILURE;

		PasswordKit::MainWindow w(&mediator);

		w.setWindowTitle(app.applicationName());
		w.show();

		app.SetMainWindow(&w);

		return app.exec();
	}
	catch(std::exception& exp)
	{
		std::cerr << exp.what();
		return EXIT_FAILURE;
	}
}
