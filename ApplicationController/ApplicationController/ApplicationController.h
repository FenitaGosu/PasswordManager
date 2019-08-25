#pragma once

#include <memory>

namespace PasswordGenerator {
class IPasswordGenerator;
}

namespace PasswordLogic {
class ICredentialsInspector;
class IDataController;
}

namespace Tools {
class StreamWrapper;
}

namespace PasswordUI {
class IUIController;
}

namespace UIProtocol {
class UIProtocolFactory;
}

namespace Controller {

class IApplicationSettings;

class ApplicationController
{
public:
	static inline const std::string ACTION_NOT_FOUND			= "Action not found.\n";
	static inline const std::string MASTER_PASSWORD_NOT_SET		= "Master password not set.\n";
	static inline const std::string MASTER_PASSWORD_INVALID		= "Master password invalid.\n";

public:
	ApplicationController();
	~ApplicationController();

	void Setup(	std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector,
				std::unique_ptr<PasswordLogic::IDataController>&& dataController,
				std::unique_ptr<Tools::StreamWrapper>&& streamWrpper,
				std::unique_ptr<PasswordGenerator::IPasswordGenerator>&& passwordGenerator,
				std::unique_ptr<PasswordUI::IUIController>&& uiController,
				std::unique_ptr<UIProtocol::UIProtocolFactory>&& uiProtocolFactory
			  );

	void Run(std::unique_ptr<IApplicationSettings>&& settings);

private:
	void SetupActionHandles();

	bool CheckMasterPassword(IApplicationSettings* settings) const;

	void HandleImpl(IApplicationSettings* settings);
	void HandleSetMasterPassword(IApplicationSettings* settings);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
	std::unique_ptr<PasswordLogic::ICredentialsInspector> m_credentialIncpector;
	std::unique_ptr<PasswordLogic::IDataController> m_dataController;
	std::unique_ptr<Tools::StreamWrapper> m_streamWrpper;
	std::unique_ptr<PasswordGenerator::IPasswordGenerator> m_passwordGenerator;
	std::unique_ptr<PasswordUI::IUIController> m_uiController;
	std::unique_ptr<UIProtocol::UIProtocolFactory> m_uiProtocolFactory;
};

}
