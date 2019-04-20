#pragma once

#include <memory>

namespace PasswordLogic {
class ICredentialsInspector;
class IDataController;
}

namespace PasswordKit {

class IApplicationSettings;

class ApplicationController
{
public:
	ApplicationController();
	~ApplicationController();

	void Setup(std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector, std::unique_ptr<PasswordLogic::IDataController>&& dataController);

	void Run(std::unique_ptr<IApplicationSettings>&& settings);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}