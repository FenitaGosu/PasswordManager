#pragma once

namespace DataBase {

class ITransactionManager;

class TransactionGuard
{
public:
	TransactionGuard(ITransactionManager * const transaction, const bool& isSuccess);
	~TransactionGuard();

private:
	const bool& m_isSuccess;
	ITransactionManager * const m_transaction;
};

}
