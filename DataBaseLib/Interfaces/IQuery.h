#pragma once

#include <memory>
#include <vector>
#include <optional>
#include <string>
#include <any>

namespace DataBase {

/**
 * Query interface
 */
class IQuery
{
public:
	using Parameters = std::vector<std::pair<std::string, std::any>>;

public:
	virtual ~IQuery() = default;

	virtual void Exec() = 0;
	virtual void Exec(const std::string& textQuery, const Parameters& values = {}) = 0;

	virtual void SetTextQuery(const std::string& textQuery) = 0;
	virtual void SetParametersQuery(const Parameters& values) = 0;

	virtual bool Next() = 0;
	virtual std::any Value(int index) const = 0;
	virtual std::optional<int> IndexOf(const std::string& name) const = 0;
};

}
