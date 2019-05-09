#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>

#include <QCoreApplication>

#include "Mediator/Mediator.h"

#include "Interfaces/IApplicationSettings.h"

#include "Encryption/CryptoHashQt/CryptoHashQt.h"

#include "Tools/StreamWrapper/StreamWrapper.h"

#include "PasswordGenerator/SimpleGenerator/SimpleGenerator.h"

#include "PasswordLogic/DataSource/DataBaseDataSource.h"
#include "PasswordLogic/CredentialsInspector/CredentialsInspector.h"
#include "PasswordLogic/DataController/DataController.h"

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

		const auto												dataBase				= std::make_shared<PasswordLogic::DataBaseDataSource>(settings->GetDataBasePath() + DATABASE_NAME);
		std::unique_ptr<PasswordLogic::ICredentialsInspector>	credentialsInspector	= std::make_unique<PasswordLogic::CredentialsInspector>(dataBase, std::make_unique<Encryption::CryptoHashQt>());
		std::unique_ptr<PasswordLogic::IDataController>			dataController			= std::make_unique<PasswordLogic::DataController>(dataBase);
		std::unique_ptr<Tools::StreamWrapper>					streamWrapper			= std::make_unique<Tools::StreamWrapper>(std::cin, std::cout);
		std::unique_ptr<PasswordGenerator::IPasswordGenerator>	passwordGenerator		= std::make_unique<PasswordGenerator::SimpleGenerator>();

		controller->Setup(std::move(credentialsInspector), std::move(dataController), std::move(streamWrapper), std::move(passwordGenerator));
		controller->Run(std::move(settings));

		return 0;
	}
	catch(std::exception& exp)
	{
		std::cerr << exp.what();
		return EXIT_FAILURE;
	}
}
