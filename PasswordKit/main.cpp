#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>

#include <QCoreApplication>

#include "Mediator/Mediator.h"

#include "Interfaces/IApplicationSettings.h"

#include "ApplicationController/ApplicationController.h"

int main(int argc, char *argv[])
{
	try
	{
		QCoreApplication app(argc, argv);

		const auto mediator = std::make_unique<PasswordKit::Mediator>();
		const auto controller = std::make_unique<PasswordKit::ApplicationController>();

		controller->Run(mediator->GetApplicationSettings());

		return 0;
	}
	catch(std::exception& exp)
	{
		std::cerr << exp.what();
		return EXIT_FAILURE;
	}
}
