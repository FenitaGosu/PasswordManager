#include <memory>

#include <QUuid>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "DataBaseLib/Interfaces/IQuery.h"
#include "DataBaseLib/DataBaseConnectionSQL/DataBaseConnectionSQL.h"
#include "DataBaseLib/TransactionManagerSQL/TransactionManagerSQL.h"

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
		m_connection.RemoveStorage();
	}

	std::shared_ptr<DataBase::ITransactionManager> GetTransactionManager()
	{
		return m_connection.GetTransactionManager();
	}

private:
	QString m_filename;
	DataBase::DataBaseConnectionSQL m_connection;
};

}

TEST(TransactionManagerSQLTest, StopTrueInTransaction)
{
	DataBaseFileGuard guard;
	const auto transaction = guard.GetTransactionManager();

	transaction->Start();
	const auto createQuery = transaction->GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();
	transaction->Stop(true);

	const auto query = transaction->GetQuery();
	ASSERT_NO_THROW(query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)"));
}

TEST(TransactionManagerSQLTest, StopFalseInTransaction)
{
	DataBaseFileGuard guard;
	const auto transaction = guard.GetTransactionManager();

	transaction->Start();
	const auto createQuery = transaction->GetQuery();
	createQuery->SetTextQuery("CREATE TABLE person (id int,forename varchar(255),surname varchar(255));");
	createQuery->Exec();
	transaction->Stop(false);

	const auto query = transaction->GetQuery();
	ASSERT_ANY_THROW(query->SetTextQuery("INSERT INTO person (id, forename, surname) VALUES (:id, :forename, :surname)"));
}
