#include <map>

#include <QSqlError>
#include <QSqlRecord>
#include <QSqlResult>
#include <QSqlQuery>

#include "Query.h"

using namespace DataBase;

struct Query::Impl
{
	Impl(const QSqlDatabase& db)
		: query(db)
	{
		query.setForwardOnly(true);
	}

	QSqlQuery query;
	std::map<QString, int> fieldIndex;
};

Query::Query(const QSqlDatabase& db)
	: m_impl(std::make_unique<Impl>(db))
{
}

IQuery::IsSuccess Query::Exec()
{
	const auto isCorrect = m_impl->query.exec();

	if (isCorrect)
	{
		m_impl->fieldIndex.clear();
		const auto record = m_impl->query.record();
		for (int i = 0, countFeild = record.count(); i < countFeild; ++i)
			m_impl->fieldIndex.emplace(std::make_pair(record.fieldName(i), i));
	}

	return MakeIsSuccess(isCorrect);
}

IQuery::IsSuccess Query::Exec(const QString& textQuery, const IQuery::Parameters& values)
{
	SetTextQuery(textQuery);
	SetParametersQuery(values);
	return Exec();
}

IQuery::IsSuccess Query::SetTextQuery(const QString& textQuery)
{
	return MakeIsSuccess(m_impl->query.prepare(textQuery));
}

IQuery::IsSuccess Query::SetParametersQuery(const IQuery::Parameters& values)
{
	for (const auto& value : values)
		m_impl->query.bindValue(value.first, value.second);

	const auto boundValues = m_impl->query.boundValues();

	const auto isCorrect = std::all_of(boundValues.cbegin(), boundValues.cend(), [](const auto& elem) { return elem.isValid(); });

	return { isCorrect, isCorrect ? QString() : "Failed to add parameters" };
}

IQuery::IsSuccess Query::Next()
{
	return MakeIsSuccess(m_impl->query.next());
}

QVariant Query::Value(int index) const
{
	return m_impl->query.value(index);
}

std::optional<int> Query::IndexOf(const QString& name) const
{
	const auto it = m_impl->fieldIndex.find(name);
	return (it == m_impl->fieldIndex.cend()) ? std::nullopt : std::optional<int>(it->second);
}

QString Query::GetError() const
{
	return "Data base error " + m_impl->query.lastError().databaseText() + ";" + "Driver error " + m_impl->query.lastError().driverText();
}

IQuery::IsSuccess Query::MakeIsSuccess(bool value)
{
	return IQuery::IsSuccess(value, value ? QString() : GetError());
}
