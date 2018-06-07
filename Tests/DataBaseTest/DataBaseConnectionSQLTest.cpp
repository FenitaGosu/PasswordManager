#include <memory>

#include <QFile>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DataBase/DataBaseConnectionSQL/DataBaseConnectionSQL.h"
#include "DataBase/TransactionManagerSQL/TransactionManagerSQL.h"

TEST(DataBaseConnectionSQLTest, OpenTrue)
{
	DataBase::DataBaseConnectionSQL connection("Test.db");
	ASSERT_NO_THROW(connection.OpenConnection());

	QFile file ("Test.db");
	file.remove();
}

TEST(DataBaseConnectionSQLTest, OpenFalse)
{
	DataBase::DataBaseConnectionSQL connection("?");
	ASSERT_ANY_THROW(connection.OpenConnection());
}

TEST(DataBaseConnectionSQLTest, GetQuery)
{
	DataBase::DataBaseConnectionSQL connection("Test.db");
	ASSERT_EQ(std::dynamic_pointer_cast<DataBase::TransactionManagerSQL>(connection.GetTransactionManager()) != nullptr, true);

	QFile file ("Test.db");
	file.remove();
}
