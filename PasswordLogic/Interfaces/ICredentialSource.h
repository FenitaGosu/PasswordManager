#pragma once

#include <string>

namespace PasswordLogic {

class ICredentialSource
{
public:
	virtual ~ICredentialSource() = default;

	virtual bool IsNeedSetPassword() const noexcept = 0;

	virtual std::string GeCurrentMainPassword() const = 0;
	virtual void SetCurrentMainPassword(const std::string& password) = 0;
};

}
