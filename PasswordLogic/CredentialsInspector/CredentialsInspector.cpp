#include "Encryption/Interfaces/ICryptoHash.h"

#include "Interfaces/ICredentialSource.h"

#include "CredentialsInspector.h"

using namespace PasswordLogic;

struct CredentialsInspector::Impl
{
	std::string GetHash(const std::string& password, const std::unique_ptr<Encryption::ICryptoHash>& hashGenerator) const
	{
		return hashGenerator->GetSha3_256(GetFrontSalt() + password + GetBackSalt());
	}

private:
	std::string GetFrontSalt() const noexcept
	{
		return std::string("8966") + std::string("e8e6");
	}

	std::string GetBackSalt() const noexcept
	{
		return std::string("b6b254") + std::string("09d053");
	}
};

CredentialsInspector::CredentialsInspector(const std::shared_ptr<ICredentialSource>& credentialSource, std::unique_ptr<Encryption::ICryptoHash>&& cryptoHash)
	: m_credentialSource(credentialSource)
	, m_cryptoHash(std::move(cryptoHash))
{
}

bool CredentialsInspector::IsNeedSetPassword() const
{
	return m_credentialSource->IsNeedSetPassword();
}

bool CredentialsInspector::CheckPassword(const std::string& password) const
{
	return m_credentialSource->GeCurrentMainPassword() == m_impl->GetHash(password, m_cryptoHash);
}

void CredentialsInspector::SetPassword(const std::string& password)
{
	m_credentialSource->SetCurrentMainPassword(m_impl->GetHash(password, m_cryptoHash));
}
