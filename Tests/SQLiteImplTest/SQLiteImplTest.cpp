#include <memory>

#include <QFile>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DataBase/SQLiteImpl/SQLiteImpl.h"

TEST(SQLiteImpl, OpenTrue)
{
	DataBase::SQLiteImpl connection("Test.db");
	ASSERT_EQ(connection.OpenConnection(), true);
}

TEST(SQLiteImpl, OpenFalse)
{
	DataBase::SQLiteImpl connection("?");
	ASSERT_EQ(connection.OpenConnection(), false);
}
