#include <map>

#include "Tools/Same/Same.h"

#include "Event/Event.h"

using namespace PasswordUI;
using namespace Tools;

namespace {

#define CONSTRUCTOR(TYPE)															\
	Event::Event(EventType type, const std::string& key, TYPE param)				\
		: Event(type)																\
	{																				\
		m_impl->parameters[key] = param;											\
	}																				\

}

struct Event::Impl
{
	std::map<std::string, Same> parameters;
};

Event::Event(EventType type)
	: m_type(type)
	, m_impl(std::make_unique<Impl>())
{
}

Event::~Event() = default;

CONSTRUCTOR(const std::string&)
CONSTRUCTOR(int)
CONSTRUCTOR(bool)

EventType Event::GetType() const noexcept
{
	return m_type;
}

std::optional<std::string> Event::GetString(const std::string& key) const
{
	const auto it = m_impl->parameters.find(key);
	return it != m_impl->parameters.cend() ? std::optional<std::string>(it->second.ToString()) : std::nullopt;
}

std::optional<int> Event::GetInt(const std::string& key) const
{
	const auto it = m_impl->parameters.find(key);
	return it != m_impl->parameters.cend() ? std::optional<int>(it->second.ToInt()) : std::nullopt;
}

std::optional<bool> Event::GetBool(const std::string& key) const
{
	const auto it = m_impl->parameters.find(key);
	return it != m_impl->parameters.cend() ? std::optional<bool>(it->second.ToBool()) : std::nullopt;
}
