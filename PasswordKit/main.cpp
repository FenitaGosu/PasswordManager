#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>

#include "Application/Application.h"
#include "ApplicationSettings/ApplicatonSettingsJsonImpl.h"

#include "PasswordLogic/Interfaces/ICredentialsInspector.h"
#include "PasswordLogic/CredentialsInspector/CredentialsInspector.h"
#include "PasswordLogic/Interfaces/IDataSource.h"
#include "PasswordLogic/DataSource/DataBaseDataSource.h"

#include "Encryption/CryptoHashQt/CryptoHashQt.h"

#include "Mediator/Mediator.h"

#include "MainWindow.h"

namespace {
const std::string DATA_SOURCE_NAME = "/PasswordManager.db";
}

int main(int argc, char *argv[])
{
	try
	{
		PasswordKit::Application app(argc, argv);
		app.СonfiguringApplicationSettings(std::make_unique<PasswordKit::ApplicatonSettingsJsonImpl>());

		const auto dataSource = std::make_shared<PasswordLogic::DataBaseDataSource>(app.GetApplicarionPath().toStdString() + DATA_SOURCE_NAME);

		PasswordKit::Mediator mediator(std::make_unique<PasswordLogic::CredentialsInspector>(dataSource, std::make_unique<Encryption::CryptoHashQt>()));

		if(!mediator.ShowLoginDialog())
			return EXIT_SUCCESS;

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
