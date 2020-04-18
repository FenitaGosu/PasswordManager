#pragma once

#include <memory>

namespace PasswordKit {

	class IApplicationSettings;

/**
 * Mediator
 */
class Mediator
{
public:
	Mediator();
	~Mediator();

	std::unique_ptr<IApplicationSettings> GetApplicationSettings() const;

private:
	void AddCommandLineOptions();

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
