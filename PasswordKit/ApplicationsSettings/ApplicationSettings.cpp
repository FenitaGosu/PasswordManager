#include "Tools/Same/Same.h"

#include "ApplicationSettings.h"

using namespace PasswordKit;

struct ApplicationSettings::Impl
{
	Impl(const std::map<std::string, Tools::Same>& values)
		: values(values)
	{
	}

	const std::map<std::string, Tools::Same> values;
};

ApplicationSettings::ApplicationSettings(const std::map<std::string, Tools::Same>& values)
	: m_impl(std::make_unique<Impl>(values))
{
}

ApplicationSettings::~ApplicationSettings() = default;
