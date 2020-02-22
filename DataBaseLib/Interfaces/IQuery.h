#pragma once

#include <memory>
#include <vector>
#include <optional>

#include <QString>
#include <QVariant>

namespace DataBase {

/**
 * Query interface
 */
class IQuery
{
public:
	using Parameters = std::vector<std::pair<QString, QVariant>>;

public:
	virtual ~IQuery() = default;

	virtual void Exec() = 0;
	virtual void Exec(const QString& textQuery, const Parameters& values = {}) = 0;

	virtual void SetTextQuery(const QString& textQuery) = 0;
	virtual void SetParametersQuery(const Parameters& values) = 0;

	virtual bool Next() = 0;
	virtual QVariant Value(int index) const = 0;
	virtual std::optional<int> IndexOf(const QString& name) const = 0;
};

}
