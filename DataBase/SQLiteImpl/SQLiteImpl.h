#pragma once

#include <memory>

#include "Interfaces/IDataBaseConnection.h"

class QString;

namespace DataBase {

class SQLiteImpl : public IDataBaseConnection
{
public:
	SQLiteImpl(const QString& path);
	~SQLiteImpl();

public:
	bool OpenConnection() override;
	void CloseConnection() override;
	std::shared_ptr<IQuery> GetQuery() const override;

private:
	bool OpenDataBase();

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
