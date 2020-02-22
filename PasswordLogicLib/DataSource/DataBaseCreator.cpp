#include <iostream>

#include "DataBaseLib/Interfaces/IDataBaseConnection.h"
#include "DataBaseLib/Interfaces/IQuery.h"
#include "DataBaseLib/Interfaces/ITransactionManager.h"

#include "DataBaseLib/TransactionManagerSQL/TransactionGuard.h"

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

		transaction->GetQuery()->Exec(DataBaseArtifacts::CREATE_ACCOUNT_TABLE);

		success = true;
	}
	catch (std::exception& exp)
	{
		std::cerr << exp.what();
	}
}
