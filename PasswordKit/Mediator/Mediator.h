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
	Mediator(int argc, char* argv[]);
	~Mediator();

	std::unique_ptr<IApplicationSettings> GetApplicationSettings() const;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
