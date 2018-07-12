#pragma once

#include <memory>

#include "Interfaces/ICredentialsInspector.h"

namespace Encryption {
class ICryptoHash;
}

namespace PasswordLogic {

class ICredentialSource;

class CredentialsInspector : public ICredentialsInspector
{
public:
	CredentialsInspector(const std::shared_ptr<ICredentialSource>& credentialSource, std::unique_ptr<Encryption::ICryptoHash>&& cryptoHash);

	bool IsNeedSetPassword() const override;
	bool CheckPassword(const std::string& password) const override;
	void SetPassword(const std::string& password) override;

private:
	std::shared_ptr<ICredentialSource> m_credentialSource;
	std::unique_ptr<Encryption::ICryptoHash> m_cryptoHash;

	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
