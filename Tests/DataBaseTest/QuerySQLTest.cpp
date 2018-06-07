#include <memory>

#include <QFile>
#include <QUuid>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DataBase/DataBaseConnectionSQL/DataBaseConnectionSQL.h"
#include "DataBase/TransactionManagerSQL/TransactionManagerSQL.h"
#include "DataBase/QuerySQL/QuerySQL.h"

namespace {

class DataBaseFileGuard
{
public:
	DataBaseFileGuard()
		: m_filename(QUuid::createUuid().toString() + ".db")
		, m_connection(m_filename)
	{
		m_connection.OpenConnection();
	}

	~DataBaseFileGuard()
	{
		m_connection.CloseConnection();
		QFile file (m_filename);
		file.remove();
	}

	std::shared_ptr<DataBase::IQuery> GetQuery()
	{
		return m_connection.GetTransactionManager()->GetQuery();
	}

private:
	QString m_filename;
	DataBase::DataBaseConnectionSQL m_connection;
};

}

TEST(QuerySQLTest, SetTextQueryValidSelect)
{
	DataBaseFileGuard guard;

	const auto query = guard.GetQuery();
	ASSERT_NO_THROW(query->SetTextQuery("CREATE TABLE Persons (PersonID int,LastName varchar(255),FirstName varchar(255),Address varchar(255),City varchar(255));"));
}

TEST(QuerySQLTest, SetTextQueryInValidSelect)
{
	DataBaseFileGuard guard;

	const auto query = guard.GetQuery();
	ASSERT_ANY_THROW(query->SetTextQuery("CREATE TAB Persons (PersonID int,LastName varchar(255),FirstName varchar(255),Address varchar(255),City varchar(255));"));
}

TEST(QuerySQLTest, SetParametersQueryValidParameters)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");

	ASSERT_NO_THROW(query->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } }));
}

TEST(QuerySQLTest, SetParametersQueryInValidParameters)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");

	ASSERT_ANY_THROW(query->SetParametersQuery({ {":idDD", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } }));
}

TEST(QuerySQLTest, ExecSuccess)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	query->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });

	ASSERT_NO_THROW(query->Exec());
}

TEST(QuerySQLTest, ExecFailed)
{
	DataBaseFileGuard guard;

	const auto query = guard.GetQuery();

	ASSERT_ANY_THROW(query->Exec());
}

TEST(QuerySQLTest, IndexOfCorrect)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = guard.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();

	ASSERT_EQ(query->IndexOf("id").has_value(), true);
}

TEST(QuerySQLTest, IndexOfInCorrect)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = guard.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();

	ASSERT_EQ(query->IndexOf("iddd").has_value(), false);
}

TEST(QuerySQLTest, ValueValid)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = guard.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();
	query->Next();

	ASSERT_EQ(query->Value(query->IndexOf("id").value()).isValid(), true);
}

TEST(QuerySQLTest, ValueInValid)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = guard.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();
	query->Next();

	ASSERT_EQ(query->Value(100).isValid(), false);
}

TEST(QuerySQLTest, NextValid)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = guard.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();

	ASSERT_EQ(query->Next(), true);
}

TEST(QuerySQLTest, NextInValid)
{
	DataBaseFileGuard guard;

	const auto createQuery = guard.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = guard.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = guard.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();
	query->Next();

	ASSERT_EQ(query->Next(), false);
}
