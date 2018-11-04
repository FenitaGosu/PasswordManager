#pragma once

#include <memory>
#include <string>
#include <optional>

#include "Enums/EventType.h"

namespace PasswordUI {

class Event
{
public:
	Event(EventType type);
	~Event();

	Event(EventType type, const std::string& key, const std::string& param);
	Event(EventType type, const std::string& key, int param);
	Event(EventType type, const std::string& key, bool param);

	EventType GetType() const noexcept;

	std::optional<std::string>	GetString(const std::string& key) const;
	std::optional<int>			GetInt(const std::string& key) const;
	std::optional<bool>			GetBool(const std::string& key) const;

private:
	EventType m_type;

	struct Impl;
	std::unique_ptr<Impl> m_impl;

};

}
