#include <map>
#include <optional>
#include <stdexcept>

#include "ToolsLib/Same/Same.h"

#include "ApplicationSettings.h"

using namespace PasswordKit;

struct ApplicationSettings::Impl
{
	Impl(const std::map<std::string, Tools::Same>& values)
		: values(values)
	{
	}

	std::optional<Tools::Same> Find(const std::string& key) const
	{
		const auto it = values.find(key);
		return it != values.cend() ? std::optional<Tools::Same>(it->second) : std::nullopt;
	}

	const std::map<std::string, Tools::Same> values;
};

ApplicationSettings::ApplicationSettings(const std::map<std::string, Tools::Same>& values)
	: m_impl(std::make_unique<Impl>(values))
{
}

ApplicationSettings::~ApplicationSettings() = default;

std::string ApplicationSettings::GetDataBasePath() const
{
	const auto value = m_impl->Find(KEY_DATABASE_PATH);
	return value.has_value() ? value.value().ToString() : std::string();
}
