#pragma once

class QSqlDatabase;

namespace DataBase {

/**
 * Database connection interface
 */
class IDataBaseConnection
{
public:
	virtual ~IDataBaseConnection() = default;

	virtual bool OpenConnection() = 0;
	virtual void CloseConnection() = 0;
	virtual QSqlDatabase GetDataBase() const = 0;
};

}
