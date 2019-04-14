#pragma once

#include <memory>

namespace PasswordKit {

class IApplicationSettings;

class ApplicationController
{
public:
	ApplicationController();
	~ApplicationController();

	void Run(std::unique_ptr<IApplicationSettings>&& settings);

private:
	struct Impl;
	std::unique_ptr<Impl> _impl;
};

}