#include <memory>

#include <QFile>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DataBase/SQLiteImpl/SQLiteImpl.h"
#include "DataBase/SQLQueryImpl/Query.h"

TEST(SQLiteImpl, OpenTrue)
{
	DataBase::SQLiteImpl connection("Test.db");
	ASSERT_EQ(connection.OpenConnection(), true);

	QFile file ("Test.db");
	file.remove();
}

TEST(SQLiteImpl, OpenFalse)
{
	DataBase::SQLiteImpl connection("?");
	ASSERT_EQ(connection.OpenConnection(), false);
}

TEST(SQLiteImpl, GetQuery)
{
	DataBase::SQLiteImpl connection("Test.db");
	ASSERT_EQ(std::dynamic_pointer_cast<DataBase::Query>(connection.GetQuery()) != nullptr, true);

	QFile file ("Test.db");
	file.remove();
}
