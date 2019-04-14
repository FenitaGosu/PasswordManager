#pragma once

#include <string>

namespace PasswordKit {

enum class Action;

class IApplicationSettings
{
public:
	inline static const std::string KEY_ACTION = "action";
	inline static const std::string DESCRIPTION_ACTION = "What should be done?";

	inline static const std::string KEY_MASTER_PASSWORD = "mpassword";
	inline static const std::string DESCRIPTION_MASTER_PASSWORD = "Master password string.";

public:
	virtual ~IApplicationSettings() = default;

	virtual std::string GetMasterPassword() const = 0;
	virtual Action GetAction() const = 0;
};

}