#include <iostream>

#include "DataBase/Interfaces/IDataBaseConnection.h"
#include "DataBase/Interfaces/IQuery.h"
#include "DataBase/Interfaces/ITransactionManager.h"

#include "DataBase/TransactionManagerSQL/TransactionGuard.h"

#include "DataBaseCreator.h"
#include "DataBaseArtifacts.h"

using namespace PasswordLogic;

void DataBaseCreator::FillDataBase(const std::unique_ptr<DataBase::IDataBaseConnection>& connection)
{
	bool success = false;
	const auto transaction = connection->GetTransactionManager();
	const auto guard = transaction->MakeGuard(success);

	try
	{
		transaction->GetQuery()->Exec(DataBaseArtifacts::CREATE_CONSTANT_TABLE);

		transaction->GetQuery()->Exec(DataBaseArtifacts::INSERT_CONSTANT,
			{ {DataBaseArtifacts::NAME, DataBaseArtifacts::MAIN_PASSWORD_CONSTANT},		{DataBaseArtifacts::VALUE, ""}});

		transaction->GetQuery()->Exec(DataBaseArtifacts::INSERT_CONSTANT,
			{ {DataBaseArtifacts::NAME, DataBaseArtifacts::DATABASE_VERSION_CONSTANT},	{DataBaseArtifacts::VALUE, DataBaseArtifacts::DATABASE_VERSION}});

		transaction->GetQuery()->Exec(DataBaseArtifacts::CREATE_ACCOUNT_PREVIEW_TABLE);

		success = true;
	}
	catch (std::exception& exp)
	{
		std::cerr << exp.what();
	}
}
