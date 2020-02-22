#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>
#include <utility>

#include <QCoreApplication>

#include "Mediator/Mediator.h"

#include "ApplicationControllerLib/Interfaces/IApplicationSettings.h"
#include "ApplicationControllerLib/ApplicationController/ApplicationController.h"

#include "EncryptionLib/CryptoHashQt/CryptoHashQt.h"

#include "ToolsLib/StreamWrapper/StreamWrapper.h"

#include "PasswordGeneratorLib/SimpleGenerator/SimpleGenerator.h"

#include "PasswordLogicLib/DataSource/DataBaseDataSource.h"
#include "PasswordLogicLib/CredentialsInspector/CredentialsInspector.h"
#include "PasswordLogicLib/DataController/DataController.h"

#include "JsonToolsLib/JsonFactory/JsonFactory.h"
#include "JsonToolsLib/ReaderQJson/ReaderQJson.h"
#include "JsonToolsLib/WriterQJson/WriterQJson.h"

namespace {

const std::string DATABASE_NAME = std::string("/PasswordManager.db");

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
		std::unique_ptr<Tools::StreamWrapper>					streamWrapper			= std::make_unique<Tools::StreamWrapper>(std::cin, std::cout);
		std::unique_ptr<PasswordGenerator::IPasswordGenerator>	passwordGenerator		= std::make_unique<PasswordGenerator::SimpleGenerator>();
		std::unique_ptr<JsonTools::JsonFactory>					jsonFactory				= std::make_unique<JsonTools::JsonFactory>([](const std::string& str) { return std::make_unique<JsonTools::ReaderQJson>(str); }, []{ return std::make_unique<JsonTools::WriterQJson>(); });

		controller->Setup(	std::move(credentialsInspector),
							std::move(dataController),
							std::move(streamWrapper),
							std::move(passwordGenerator),
							std::move(jsonFactory)
						);

		controller->Run(std::move(settings));

		return 0;
	}
	catch(std::exception& exp)
	{
		std::cerr << exp.what();
		return EXIT_FAILURE;
	}
}
