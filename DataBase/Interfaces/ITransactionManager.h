#pragma once

#include <memory>

namespace DataBase {

class IQuery;

/**
 * Transaction manager interface
 */
class ITransactionManager
{
public:
	virtual ~ITransactionManager() = default;

	virtual void Start() = 0;
	virtual void Stop(bool success) = 0;
	virtual std::shared_ptr<IQuery> GetQuery() const = 0;
};

}
