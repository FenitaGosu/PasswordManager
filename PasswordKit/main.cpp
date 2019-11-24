#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>
#include <utility>

#include <QCoreApplication>

#include "Mediator/Mediator.h"

#include "ApplicationController/Interfaces/IApplicationSettings.h"

#include "Encryption/CryptoHashQt/CryptoHashQt.h"

#include "Tools/StreamWrapper/StreamWrapper.h"

#include "PasswordGenerator/SimpleGenerator/SimpleGenerator.h"

#include "PasswordLogic/DataSource/DataBaseDataSource.h"
#include "PasswordLogic/CredentialsInspector/CredentialsInspector.h"
#include "PasswordLogic/DataController/DataController.h"

#include "PasswordUI/UIController/UIController.h"

#include "UIProtocol/ProtocolFactory/UIProtocolFactory.h"
#include "UIProtocol/Protocol/Protocol.h"

#include "JsonTools/JsonFactory/JsonFactory.h"
#include "JsonTools/ReaderQJson/ReaderQJson.h"
#include "JsonTools/WriterQJson/WriterQJson.h"

#include "ApplicationController/ApplicationController/ApplicationController.h"

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
		std::unique_ptr<PasswordUI::IUIController>				uiController			= std::make_unique<PasswordUI::UIController>();
		std::unique_ptr<UIProtocol::UIProtocolFactory>			uiProtocolFactory		= std::make_unique<UIProtocol::UIProtocolFactory>(UIProtocol::ProtocolType::JSON, []{ return std::make_unique<UIProtocol::Protocol>(); });
		std::unique_ptr<JsonTools::JsonFactory>					jsonFactory				= std::make_unique<JsonTools::JsonFactory>([](const std::string& str) { return std::make_unique<JsonTools::ReaderQJson>(str); }, []{ return std::make_unique<JsonTools::WriterQJson>(); });

		controller->Setup(	std::move(credentialsInspector),
							std::move(dataController),
							std::move(streamWrapper),
							std::move(passwordGenerator),
							std::move(uiController),
							std::move(uiProtocolFactory),
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
