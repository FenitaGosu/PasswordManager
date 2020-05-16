#pragma once

#include "DataBaseLib/Interfaces/IQuery.h"

class QSqlDatabase;

namespace DataBase {

/**
 * QSqlQuery implementation of the interface IQuery
 */
class QuerySQL : public IQuery
{
public:
	QuerySQL(const QSqlDatabase& db);

	void Exec() override;
	void Exec(const std::string& textQuery, const Parameters& values = {}) override;

	void SetTextQuery(const std::string& textQuery) override;
	void SetParametersQuery(const Parameters& values) override;

	bool Next() override;
	std::any Value(int index) const override;
	std::optional<int> IndexOf(const std::string& name) const override;

private:
	std::string GetError() const;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
