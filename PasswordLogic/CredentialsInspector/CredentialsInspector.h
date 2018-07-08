#pragma once

#include "Interfaces/ICredentialsInspector.h"

namespace PasswordLogic {

class CredentialsInspector : public ICredentialsInspector
{
public:
	CredentialsInspector();

	bool IsFirstStart() const override;
	bool CheckPassword(const std::string& password) const override;
	void SetPassword(const std::string& password) override;

private:
	std::string m_password;
};

}
