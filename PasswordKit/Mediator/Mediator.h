#pragma once

#include <memory>

namespace Controller {
class IApplicationSettings;
}

namespace PasswordKit {

/**
 * Mediator
 */
class Mediator
{
public:
	Mediator();
	~Mediator();

	std::unique_ptr<Controller::IApplicationSettings> GetApplicationSettings() const;

private:
	void AddCommandLineOptions();

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
