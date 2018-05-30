#pragma once

#include <memory>

class QSqlDatabase;

namespace DataBase {

class IQuery;

/**
 * Database connection interface
 */
class IDataBaseConnection
{
public:
	virtual ~IDataBaseConnection() = default;

	virtual bool OpenConnection() = 0;
	virtual void CloseConnection() = 0;
	virtual std::shared_ptr<IQuery> GetQuery() const = 0;
};

}
