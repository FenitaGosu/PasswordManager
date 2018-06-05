#include <memory>

#include <QFile>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DataBase/DataBaseConnectionSQL/DataBaseConnectionSQL.h"
#include "DataBase/QuerySQL/QuerySQL.h"

TEST(SQLiteImpl, OpenTrue)
{
	DataBase::DataBaseConnectionSQL connection("Test.db");
	ASSERT_NO_THROW(connection.OpenConnection());

	QFile file ("Test.db");
	file.remove();
}

TEST(SQLiteImpl, OpenFalse)
{
	DataBase::DataBaseConnectionSQL connection("?");
	ASSERT_ANY_THROW(connection.OpenConnection());
}

TEST(SQLiteImpl, GetQuery)
{
	DataBase::DataBaseConnectionSQL connection("Test.db");
	ASSERT_EQ(std::dynamic_pointer_cast<DataBase::QuerySQL>(connection.GetQuery()) != nullptr, true);

	QFile file ("Test.db");
	file.remove();
}
