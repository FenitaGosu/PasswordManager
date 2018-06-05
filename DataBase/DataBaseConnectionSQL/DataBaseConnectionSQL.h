#pragma once

#include <memory>

#include "Interfaces/IDataBaseConnection.h"

class QString;

namespace DataBase {

class DataBaseConnectionSQL : public IDataBaseConnection
{
public:
	DataBaseConnectionSQL(const QString& path);
	~DataBaseConnectionSQL();

public:
	void OpenConnection() override;
	void CloseConnection() override;
	std::shared_ptr<ITransactionManager> GetTransactionManager() const override;

private:
	void OpenDataBase();

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
