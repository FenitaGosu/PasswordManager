#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>

#include <QCoreApplication>

#include "Mediator/Mediator.h"

#include "Interfaces/IApplicationSettings.h"

#include "Encryption/CryptoHashQt/CryptoHashQt.h"

#include "PasswordLogic/DataSource/DataBaseDataSource.h"
#include "PasswordLogic/CredentialsInspector/CredentialsInspector.h"

#include "ApplicationController/ApplicationController.h"

namespace {

const std::string DATABASE_NAME = std::string("/PasswordManager.db");

}

int main(int argc, char *argv[])
{
	try
	{
		QCoreApplication app(argc, argv); // for commandline parser

		const auto mediator		= std::make_unique<PasswordKit::Mediator>();
		const auto controller	= std::make_unique<PasswordKit::ApplicationController>();

		auto settings = mediator->GetApplicationSettings();

		const auto dataBase															= std::make_shared<PasswordLogic::DataBaseDataSource>(settings->GetDataBasePath() + DATABASE_NAME);
		std::unique_ptr<PasswordLogic::ICredentialsInspector> credentialsInspector	= std::make_unique<PasswordLogic::CredentialsInspector>(dataBase, std::make_unique<Encryption::CryptoHashQt>());

		controller->Setup(std::move(credentialsInspector));

		controller->Run(std::move(settings));

		return 0;
	}
	catch(std::exception& exp)
	{
		std::cerr << exp.what();
		return EXIT_FAILURE;
	}
}
