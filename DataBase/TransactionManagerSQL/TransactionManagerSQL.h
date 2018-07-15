#pragma once

#include "Interfaces/ITransactionManager.h"

class QSqlDatabase;

namespace DataBase {

/**
 * Implementation of the interface ITransactionManager
 */
class TransactionManagerSQL : public ITransactionManager
{
public:
	TransactionManagerSQL(const QSqlDatabase& db);

	std::unique_ptr<TransactionGuard> MakeGuard(const bool& isSuccess) override;
	void Start() override;
	void Stop(bool success) override;
	std::shared_ptr<IQuery> GetQuery() const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
