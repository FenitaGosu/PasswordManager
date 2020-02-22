#include <iostream>
#include <cassert>

#include "DataBaseLib/Interfaces/IDataBaseConnection.h"
#include "DataBaseLib/Interfaces/IQuery.h"
#include "DataBaseLib/Interfaces/ITransactionManager.h"

#include "DataBaseLib/TransactionManagerSQL/TransactionGuard.h"

#include "DataBaseMigrator.h"
#include "DataBaseArtifacts.h"

using namespace PasswordLogic;
using namespace DataBase;

void DataBaseMigrator::MigrateDataBase(const std::unique_ptr<IDataBaseConnection>& connection)
{
	static const std::vector<std::function<void(const std::unique_ptr<IDataBaseConnection>&, const std::shared_ptr<ITransactionManager>&)>> s_migrateFunctions =
	{
		[](const auto&, const auto&){}, // zero function is fake function
	};

	bool success = false;
	const auto transaction = connection->GetTransactionManager();
	const auto guard = transaction->MakeGuard(success);

	try
	{
		const auto query = transaction->GetQuery();
		size_t currentVersion = 0;

		query->Exec(DataBaseArtifacts::SELECT_CONSTANT, { {DataBaseArtifacts::NAME, DataBaseArtifacts::DATABASE_VERSION_CONSTANT} } );

		if (query->Next())
			currentVersion = static_cast<size_t>(query->Value(query->IndexOf(DataBaseArtifacts::VALUE_INDEX).value()).toString().toInt());

		assert(currentVersion);

		for (size_t i = currentVersion; i < DataBaseArtifacts::DATABASE_VERSION; ++i)
			s_migrateFunctions[i](connection, transaction);

		success = true;
	}
	catch (std::exception& exp)
	{
		std::cerr << exp.what();
	}
}
