#include <map>
#include <stdexcept>

#include <QSqlError>
#include <QSqlRecord>
#include <QSqlResult>
#include <QSqlQuery>

#include "QuerySQL.h"

using namespace DataBase;

namespace {

	std::any QVariantToStdAny(const QVariant& var)
	{
		switch (var.userType())
		{
		case QVariant::Bool:
			return std::any(var.value<bool>());
		case QVariant::Int:
			return std::any(var.value<int>());
		case QVariant::LongLong:
			return std::any(var.value<long long>());
		case QVariant::UInt:
			return std::any(var.value<unsigned>());
		case QVariant::String:
			return std::any(var.toString().toStdString());
		case QVariant::Double:
			return std::any(var.value<double>());
		case QVariant::Invalid:
			return std::any();
		default:
			throw std::runtime_error(std::string("Unknown type: ") + std::string(var.typeName()) + ".");
		}
	}

	QVariant StdAnyToQVariant(const std::any& any)
	{
		if (any.type() == typeid(bool))
			return QVariant::fromValue(std::any_cast<bool>(any));
		else if (any.type() == typeid(int))
			return QVariant::fromValue(std::any_cast<int>(any));
		else if (any.type() == typeid(unsigned))
			return QVariant::fromValue(std::any_cast<unsigned>(any));
		else if (any.type() == typeid(long long))
			return QVariant::fromValue(std::any_cast<long long>(any));
		else if (any.type() == typeid(std::string))
			return QVariant::fromValue(QString::fromStdString(std::any_cast<std::string>(any)));
		else if (any.type() == typeid(const char*))
			return QVariant::fromValue(QString(std::any_cast<const char*>(any)));
		else if (any.type() == typeid(double))
			return QVariant::fromValue(std::any_cast<double>(any));
		else if (any.type() == typeid(void))
			return QVariant();

		throw std::runtime_error(std::string("Unknown type: ") + std::string(any.type().name()) + ".");
	}
}

struct QuerySQL::Impl
{
	Impl(const QSqlDatabase& db)
		: query(db)
	{
		query.setForwardOnly(true);
	}

	QSqlQuery query;
	std::map<QString, int> fieldIndex;
};

QuerySQL::QuerySQL(const QSqlDatabase& db)
	: m_impl(std::make_unique<Impl>(db))
{
}

void QuerySQL::Exec()
{
	if (!m_impl->query.exec())
		throw std::logic_error("Request could not be completed: " + GetError());

	m_impl->fieldIndex.clear();
	const auto record = m_impl->query.record();
	for (int i = 0, countFeild = record.count(); i < countFeild; ++i)
		m_impl->fieldIndex.emplace(record.fieldName(i), i);

}

void QuerySQL::Exec(const std::string& textQuery, const IQuery::Parameters& values)
{
	SetTextQuery(textQuery);
	SetParametersQuery(values);
	Exec();
}

void QuerySQL::SetTextQuery(const std::string& textQuery)
{
	if (!m_impl->query.prepare(QString::fromStdString(textQuery)))
		throw std::logic_error("Request preparation failed: " + GetError());
}

void QuerySQL::SetParametersQuery(const IQuery::Parameters& values)
{
	for (const auto& value : values)
		m_impl->query.bindValue(QString::fromStdString(value.first), StdAnyToQVariant(value.second));

	const auto boundValues = m_impl->query.boundValues();

	const auto isCorrect = std::all_of(boundValues.cbegin(), boundValues.cend(), [](const auto& elem) { return elem.isValid(); });

	if (!isCorrect)
		throw std::logic_error("Failed to add parameters");
}

bool QuerySQL::Next()
{
	return m_impl->query.next();
}

std::any QuerySQL::Value(int index) const
{
	return QVariantToStdAny(m_impl->query.value(index));
}

std::optional<int> QuerySQL::IndexOf(const std::string& name) const
{
	const auto it = m_impl->fieldIndex.find(QString::fromStdString(name));
	return (it == m_impl->fieldIndex.cend()) ? std::nullopt : std::optional<int>(it->second);
}

std::string QuerySQL::GetError() const
{
	return m_impl->query.lastError().text().toStdString();
}
