#pragma once

namespace PasswordUI {

class Event;

class IEventHandler
{
public:
	virtual ~IEventHandler() = default;
	virtual void HandleEvent(Event& e) = 0;
	virtual void HandleEvent(Event&& e) = 0;
};

}
