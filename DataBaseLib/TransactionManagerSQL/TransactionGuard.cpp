#include "DataBaseLib/Interfaces/ITransactionManager.h"

#include "TransactionGuard.h"

using namespace DataBase;

TransactionGuard::TransactionGuard(ITransactionManager * const transaction, const bool& isSuccess)
	: m_isSuccess(isSuccess)
	, m_transaction(transaction)
{
	m_transaction->Start();
}

TransactionGuard::~TransactionGuard()
{
	m_transaction->Stop(m_isSuccess);
}
