#include <memory>

#include <QFile>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "DataBaseLib/DataBaseConnectionSQL/DataBaseConnectionSQL.h"
#include "DataBaseLib/TransactionManagerSQL/TransactionManagerSQL.h"

TEST(DataBaseConnectionSQLTest, OpenTrue)
{
	DataBase::DataBaseConnectionSQL connection("Test.db");
	ASSERT_NO_THROW(connection.OpenConnection());

	connection.CloseConnection();
	connection.RemoveStorage();
}

TEST(DataBaseConnectionSQLTest, OpenNewConnection)
{
	DataBase::DataBaseConnectionSQL connection("Test.db");
	ASSERT_EQ(connection.OpenConnection(), DataBase::IDataBaseConnection::OpenStatus::OpenNew);

	connection.CloseConnection();
	connection.RemoveStorage();
}

TEST(DataBaseConnectionSQLTest, OpenFalse)
{
	DataBase::DataBaseConnectionSQL connection("?");
	ASSERT_ANY_THROW(connection.OpenConnection());
}

TEST(DataBaseConnectionSQLTest, RemoveStorage)
{
	DataBase::DataBaseConnectionSQL connection("Test.db");
	connection.OpenConnection();

	connection.CloseConnection();
	connection.RemoveStorage();

	ASSERT_EQ(QFile::exists("Test.db"), false);
}

TEST(DataBaseConnectionSQLTest, GetQuery)
{
	DataBase::DataBaseConnectionSQL connection("Test.db");
	ASSERT_EQ(std::dynamic_pointer_cast<DataBase::TransactionManagerSQL>(connection.GetTransactionManager()) != nullptr, true);

	connection.CloseConnection();
	connection.RemoveStorage();
}
