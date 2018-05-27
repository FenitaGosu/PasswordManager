#include <memory>

#include <QFile>
#include <QUuid>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DataBase/SQLiteImpl/SQLiteImpl.h"
#include "DataBase/SQLQueryImpl/Query.h"

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

	DataBase::SQLiteImpl& GetConnection()
	{
		return m_connection;
	}

private:
	QString m_filename;
	DataBase::SQLiteImpl m_connection;
};

}

TEST(SQLQueryImpl, SetTextQueryValidSelect)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto query = connection.GetQuery();
	const auto res = query->SetTextQuery("CREATE TABLE Persons (PersonID int,LastName varchar(255),FirstName varchar(255),Address varchar(255),City varchar(255));");
	ASSERT_EQ(res.first, true);
}

TEST(SQLQueryImpl, SetTextQueryInValidSelect)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto query = connection.GetQuery();
	const auto res = query->SetTextQuery("CREATE TAB Persons (PersonID int,LastName varchar(255),FirstName varchar(255),Address varchar(255),City varchar(255));");
	ASSERT_EQ(res.first, false);
}

TEST(SQLQueryImpl, SetParametersQueryValidParameters)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto query = connection.GetQuery();
	query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");

	const auto res = query->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	ASSERT_EQ(res.first, true);
}

TEST(SQLQueryImpl, SetParametersQueryInValidParameters)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto query = connection.GetQuery();
	query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");

	const auto res = query->SetParametersQuery({ {":idDD", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	ASSERT_EQ(res.first, false);
}

TEST(SQLQueryImpl, ExecSuccess)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto createQuery = connection.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto query = connection.GetQuery();
	query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	query->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	const auto res = query->Exec();
	ASSERT_EQ(res.first, true);
}

TEST(SQLQueryImpl, ExecFailed)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto query = connection.GetQuery();
	query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	query->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	const auto res = query->Exec();
	ASSERT_EQ(res.first, false);
}

TEST(SQLQueryImpl, IndexOfCorrect)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto createQuery = connection.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = connection.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = connection.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();

	ASSERT_EQ(query->IndexOf("id").has_value(), true);
}

TEST(SQLQueryImpl, IndexOfInCorrect)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto createQuery = connection.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = connection.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = connection.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();

	ASSERT_EQ(query->IndexOf("iddd").has_value(), false);
}

TEST(SQLQueryImpl, ValueValid)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto createQuery = connection.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = connection.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = connection.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();
	query->Next();

	ASSERT_EQ(query->Value(query->IndexOf("id").value()).isValid(), true);
}

TEST(SQLQueryImpl, ValueInValid)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto createQuery = connection.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = connection.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = connection.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();
	query->Next();

	ASSERT_EQ(query->Value(100).isValid(), false);
}

TEST(SQLQueryImpl, NextValid)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto createQuery = connection.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = connection.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = connection.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();

	ASSERT_EQ(query->Next().first, true);
}

TEST(SQLQueryImpl, NextInValid)
{
	DataBaseFileGuard guard;
	auto& connection = guard.GetConnection();

	const auto createQuery = connection.GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();

	const auto insertQuery = connection.GetQuery();
	insertQuery->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)");
	insertQuery->SetParametersQuery({ {":id", 1001}, {":forename", "Bart"}, {":surname", "Simpson" } });
	insertQuery->Exec();

	const auto query = connection.GetQuery();
	query->SetTextQuery("SELECT * FROM person");
	query->Exec();
	query->Next();

	ASSERT_EQ(query->Next().first, false);
}
