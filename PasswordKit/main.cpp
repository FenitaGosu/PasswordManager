#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>
#include <utility>

#include <QCoreApplication>

#include "ApplicationControllerLib/Interfaces/IApplicationSettings.h"
#include "ApplicationControllerLib/ApplicationController/ApplicationController.h"

#include "EncryptionLib/CryptoHashQt/CryptoHashQt.h"

#include "PasswordGeneratorLib/SimpleGenerator/SimpleGenerator.h"

#include "PasswordLogicLib/DataSource/DataBaseDataSource.h"
#include "PasswordLogicLib/CredentialsInspector/CredentialsInspector.h"
#include "PasswordLogicLib/DataController/DataController.h"
#include "PasswordLogicLib/PasswordApi/PasswordApi.h"

#include "Mediator/Mediator.h"
#include "Streams/StandartStreamsWrapper.h"
#include "ApiProxy/ApiProxy.h"

namespace {
const std::string DATABASE_NAME = "/PasswordManager.db";
}

int main(int argc, char *argv[])
{
	try
	{
		QCoreApplication app(argc, argv); // for commandline parser

		const auto mediator		= std::make_unique<PasswordKit::Mediator>();
		const auto controller	= std::make_unique<Controller::ApplicationController>();

		auto settings = mediator->GetApplicationSettings();

		const auto												dataBase				= std::make_shared<PasswordLogic::DataBaseDataSource>(settings->GetDataBasePath() + DATABASE_NAME);
		std::unique_ptr<PasswordLogic::ICredentialsInspector>	credentialsInspector	= std::make_unique<PasswordLogic::CredentialsInspector>(dataBase, std::make_unique<Encryption::CryptoHashQt>());
		std::unique_ptr<PasswordLogic::IDataController>			dataController			= std::make_unique<PasswordLogic::DataController>(dataBase);
		std::unique_ptr<PasswordGenerator::IPasswordGenerator>	passwordGenerator		= std::make_unique<PasswordGenerator::SimpleGenerator>();
		std::unique_ptr<PasswordLogic::IPasswordApi>			passwordApi				= std::make_unique<PasswordLogic::PasswordApi>(std::move(credentialsInspector), std::move(dataController), std::move(passwordGenerator));
		std::unique_ptr<Controller::IDataStream>				dataStream				= std::make_unique<PasswordKit::StandartStreamsWrapper>(std::cin, std::cout);
		std::unique_ptr<Controller::IApiProxy>					apiProxy				= std::make_unique<PasswordKit::ApiProxy>(std::move(passwordApi));

		controller->Setup(std::move(apiProxy), std::move(dataStream));

		controller->Run(std::move(settings));

		return 0;
	}
	catch(std::exception& exp)
	{
		std::cerr << exp.what();
		return EXIT_FAILURE;
	}
}
