#include <exception>

#include <QSqlDatabase>
#include <QFile>
#include <QUuid>
#include <QSqlError>

#include "DataBaseLib/TransactionManagerSQL/TransactionManagerSQL.h"

#include "DataBaseConnectionSQL.h"

namespace {
const QString DATABASE_TYPE = "QSQLITE";
}

using namespace DataBase;

struct DataBaseConnectionSQL::Impl
{
	Impl(const QString& Path, const QString& ConnectionName)
		: path(Path)
		, connectionName(ConnectionName)
	{
	}

	QString path;
	QString connectionName;
};

DataBaseConnectionSQL::DataBaseConnectionSQL(const QString& path)
	: m_impl(std::make_unique<Impl>(path, QUuid::createUuid().toString()))
{
}

DataBaseConnectionSQL::~DataBaseConnectionSQL()
{
	CloseConnection();
}

IDataBaseConnection::OpenStatus DataBaseConnectionSQL::OpenConnection()
{
	return OpenDataBase();
}

void DataBaseConnectionSQL::CloseConnection()
{
	QSqlDatabase::database(m_impl->connectionName).close();
	QSqlDatabase::removeDatabase(m_impl->connectionName);
}

void DataBaseConnectionSQL::RemoveStorage()
{
	QFile::remove(m_impl->path);
}

std::shared_ptr<ITransactionManager> DataBaseConnectionSQL::GetTransactionManager() const
{
	return std::make_shared<TransactionManagerSQL>(QSqlDatabase::database(m_impl->connectionName));
}

IDataBaseConnection::OpenStatus DataBaseConnectionSQL::OpenDataBase()
{
	OpenStatus status =  QFile::exists(m_impl->path) ? OpenStatus::OpenExisting : OpenStatus::OpenNew;
	auto db = QSqlDatabase::addDatabase(DATABASE_TYPE, m_impl->connectionName);
	db.setDatabaseName(m_impl->path);

	if (!db.open())
		throw std::logic_error("Сonnection could not be opened: " + db.lastError().text().toStdString());

	return status;
}
