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
	using IsSuccess = std::pair<bool, QString>;

public:
	virtual ~IQuery() = default;

	virtual IsSuccess Exec() = 0;
	virtual IsSuccess Exec(const QString& textQuery, const Parameters& values = {}) = 0;

	virtual IsSuccess SetTextQuery(const QString& textQuery) = 0;
	virtual IsSuccess SetParametersQuery(const Parameters& values) = 0;

	virtual IsSuccess Next() = 0;
	virtual QVariant Value(int index) const = 0;
	virtual std::optional<int> IndexOf(const QString& name) const = 0;
};

}
