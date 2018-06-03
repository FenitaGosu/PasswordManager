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

void Query::Exec()
{
	if (!m_impl->query.exec())
		throw std::logic_error("Request could not be completed: " + GetError());

	m_impl->fieldIndex.clear();
	const auto record = m_impl->query.record();
	for (int i = 0, countFeild = record.count(); i < countFeild; ++i)
		m_impl->fieldIndex.emplace(record.fieldName(i), i);

}

void Query::Exec(const QString& textQuery, const IQuery::Parameters& values)
{
	SetTextQuery(textQuery);
	SetParametersQuery(values);
	Exec();
}

void Query::SetTextQuery(const QString& textQuery)
{
	if (!m_impl->query.prepare(textQuery))
		throw std::logic_error("Request preparation failed: " + GetError());
}

void Query::SetParametersQuery(const IQuery::Parameters& values)
{
	for (const auto& value : values)
		m_impl->query.bindValue(value.first, value.second);

	const auto boundValues = m_impl->query.boundValues();

	const auto isCorrect = std::all_of(boundValues.cbegin(), boundValues.cend(), [](const auto& elem) { return elem.isValid(); });

	if (!isCorrect)
		throw std::logic_error("Failed to add parameters");
}

bool Query::Next()
{
	return m_impl->query.next();
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

std::string Query::GetError() const
{
	return m_impl->query.lastError().text().toStdString();
}
