#pragma once

#include "Interfaces/IQuery.h"

class QSqlDatabase;

namespace DataBase {

/**
 * QSqlQuery implementation of the interface IQuery.
 */
class Query : public IQuery
{
public:
	Query(const QSqlDatabase& db);

	IsSuccess Exec() override;
	IsSuccess Exec(const QString& textQuery, const Parameters& values = {}) override;

	IsSuccess SetTextQuery(const QString& textQuery) override;
	IsSuccess SetParametersQuery(const Parameters& values) override;

	IsSuccess Next() override;
	QVariant Value(int index) const override;
	std::optional<int> IndexOf(const QString& name) const override;

private:
	QString GetError() const;
	IQuery::IsSuccess MakeIsSuccess(bool value);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
