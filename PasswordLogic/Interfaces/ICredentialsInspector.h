#pragma once

#include <string>

namespace PasswordLogic {

class ICredentialsInspector
{
public:
	virtual ~ICredentialsInspector() = default;

	virtual	bool IsFirstStart() const = 0;
	virtual bool CheckPassword(const std::string& password) const = 0;
	virtual void SetPassword(const std::string& password) = 0;
};

}
