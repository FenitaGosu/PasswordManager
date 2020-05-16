#pragma once

#include <memory>

#include "DataBaseLib/Interfaces/IDataBaseConnection.h"

namespace DataBase {

class DataBaseConnectionSQL : public IDataBaseConnection
{
public:
	DataBaseConnectionSQL(const std::string& path);
	~DataBaseConnectionSQL();

public:
	OpenStatus OpenConnection() override;
	void CloseConnection() override;
	void RemoveStorage() override;
	std::shared_ptr<ITransactionManager> GetTransactionManager() const override;

private:
	OpenStatus OpenDataBase();

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
