#pragma once

#include "Interfaces/ICredentialsInspector.h"

namespace PasswordLogic {

class CredentialsInspector : public ICredentialsInspector
{
public:
	CredentialsInspector();

	bool IsFirstStart() const override;
	bool CheckPassword() const override;
	void SetPassword(const std::string& password) override;
};

}
