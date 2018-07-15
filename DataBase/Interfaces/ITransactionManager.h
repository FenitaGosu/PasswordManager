#pragma once

#include <memory>

namespace DataBase {

class IQuery;
class TransactionGuard;

/**
 * Transaction manager interface
 */
class ITransactionManager
{
public:
	virtual ~ITransactionManager() = default;

	[[nodiscard]] virtual std::unique_ptr<TransactionGuard> MakeGuard(const bool& isSuccess) = 0;
	virtual void Start() = 0;
	virtual void Stop(bool success) = 0;
	virtual std::shared_ptr<IQuery> GetQuery() const = 0;
};

}
