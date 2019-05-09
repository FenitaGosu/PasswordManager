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

namespace PasswordKit {

class IApplicationSettings;

class ApplicationController
{
public:
	static inline const std::string ACTION_NOT_FOUND			= "Action not found.\n";
	static inline const std::string MASTER_PASSWORD_NOT_SET		= "Master password not set.\n";
	static inline const std::string MASTER_PASSWORD_INVALID		= "Master password invalid.\n";
	static inline const std::string GENERATE_PASSWORD_OR_INPUT	= "Want to generate a password or input g/i (e exit)?\n";
	static inline const std::string SYMBOLS_NAMBER				= "Enter the number of symbols (>= %i).\n";
	static inline const std::string PASSWORD_CHANGED			= "Password successfully changed.";
	static inline const std::string INPUT_PASSWORD				= "Enter password (symbols >= %i).\n";
	static inline const std::string GENERATED_PASSWORD			= "Generated password: %s \n";

public:
	ApplicationController();
	~ApplicationController();

	void Setup(	std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector,
				std::unique_ptr<PasswordLogic::IDataController>&& dataController,
				std::unique_ptr<Tools::StreamWrapper>&& streamWrpper,
				std::unique_ptr<PasswordGenerator::IPasswordGenerator>&& passwordGenerator
			  );

	void Run(std::unique_ptr<IApplicationSettings>&& settings);

private:
	void SetupActionHandles();

	bool CheckMasterPassword(IApplicationSettings* settings) const;

	std::string GeneratePassword() const;
	std::string ReadPassword() const;

	void HandleImpl(IApplicationSettings* settings);
	void HandleSetMasterPassword(IApplicationSettings* settings);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}