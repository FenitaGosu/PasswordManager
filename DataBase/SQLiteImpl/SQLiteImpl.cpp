#include <exception>

#include <QSqlDatabase>
#include <QFile>
#include <QUuid>
#include <QSqlError>

#include "SQLQueryImpl/Query.h"

#include "SQLiteImpl.h"

namespace {
const QString DATABASE_TYPE = "QSQLITE";
}

using namespace DataBase;

struct SQLiteImpl::Impl
{
	Impl(const QString& Path, const QString& ConnectionName)
		: path(Path)
		, connectionName(ConnectionName)
	{
	}

	QString path;
	QString connectionName;
};

SQLiteImpl::SQLiteImpl(const QString& path)
	: m_impl(std::make_unique<Impl>(path, QUuid::createUuid().toString()))
{
}

SQLiteImpl::~SQLiteImpl()
{
	CloseConnection();
}

void SQLiteImpl::OpenConnection()
{
	OpenDataBase();
}

void SQLiteImpl::CloseConnection()
{
	QSqlDatabase::database(m_impl->connectionName).close();
	QSqlDatabase::removeDatabase(m_impl->connectionName);
}

std::shared_ptr<IQuery> SQLiteImpl::GetQuery() const
{
	return std::make_shared<Query>(QSqlDatabase::database(m_impl->connectionName));
}

void SQLiteImpl::OpenDataBase()
{
	auto db = QSqlDatabase::addDatabase(DATABASE_TYPE, m_impl->connectionName);
	db.setDatabaseName(m_impl->path);

	if (!db.open())
		throw std::logic_error("Сonnection could not be opened: " + db.lastError().text().toStdString());
}
