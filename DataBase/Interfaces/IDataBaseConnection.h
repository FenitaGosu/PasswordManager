#pragma once

#include <memory>

class QSqlDatabase;

namespace DataBase {

class ITransactionManager;

/**
 * Database connection interface
 */
class IDataBaseConnection
{
public:
	virtual ~IDataBaseConnection() = default;

	virtual void OpenConnection() = 0;
	virtual void CloseConnection() = 0;
	virtual std::shared_ptr<ITransactionManager> GetTransactionManager() const = 0;
};

}
