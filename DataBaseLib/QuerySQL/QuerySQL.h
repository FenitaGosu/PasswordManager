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
	void Exec(const QString& textQuery, const Parameters& values = {}) override;

	void SetTextQuery(const QString& textQuery) override;
	void SetParametersQuery(const Parameters& values) override;

	bool Next() override;
	QVariant Value(int index) const override;
	std::optional<int> IndexOf(const QString& name) const override;

private:
	std::string GetError() const;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
