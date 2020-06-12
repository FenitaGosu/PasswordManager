#include <stdexcept>

#include <QSqlQuery>
#include <QSqlError>

#include "DataBaseLib/QuerySQL/QuerySQL.h"

#include "TransactionGuard.h"
#include "TransactionManagerSQL.h"

using namespace DataBase;

struct TransactionManagerSQL::Impl
{
	Impl(const QSqlDatabase& db)
		: dbConnection(db)
	{
	}

	QSqlDatabase dbConnection;
};

TransactionManagerSQL::TransactionManagerSQL(const QSqlDatabase& db)
	: m_impl(std::make_unique<Impl>(db))
{
}

std::unique_ptr<TransactionGuard> TransactionManagerSQL::MakeGuard(const bool& isSuccess)
{
	return std::make_unique<TransactionGuard>(this, isSuccess);
}

void TransactionManagerSQL::Start()
{
	if (!m_impl->dbConnection.transaction())
		throw std::logic_error("Transaction could not be started: " + m_impl->dbConnection.lastError().text().toStdString());
}

void TransactionManagerSQL::Stop(bool success)
{
	if (success)
	{
		if (!m_impl->dbConnection.commit())
			throw std::logic_error("Transaction could not be comited: " + m_impl->dbConnection.lastError().text().toStdString());
	}
	else
	{
		if (!m_impl->dbConnection.rollback())
			throw std::logic_error("Transaction could not be rollbacked: " + m_impl->dbConnection.lastError().text().toStdString());
	}
}

std::shared_ptr<IQuery> TransactionManagerSQL::GetQuery() const
{
	return std::make_shared<QuerySQL>(m_impl->dbConnection);
}
