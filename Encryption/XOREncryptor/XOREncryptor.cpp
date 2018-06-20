#include <string>
#include <algorithm>

#include "XOREncryptor.h"

#include "Interfaces/IKeyProvider.h"

using namespace Encryption;

XOREncryptor::XOREncryptor(std::unique_ptr<IKeyProvider>&& provider)
	: m_keyProvider(std::move(provider))
{
}

XOREncryptor::~XOREncryptor() = default;

std::string XOREncryptor::Encrypt(const std::string& msg) const
{
	return Impl(msg);
}

std::string XOREncryptor::Decrypt(const std::string& encryptedMsg) const
{
	return Impl(encryptedMsg);
}

std::string XOREncryptor::Impl(const std::string& str) const
{
	if (m_keyProvider->GetStringKey().empty())
		throw std::logic_error("Key must be nonzero");

	const auto key = m_keyProvider->GetStringKey();
	const auto keySize = key.size();
	std::string res;
	res.reserve(str.size());

	for (size_t i = 0, sz = str.size(); i < sz; ++i)
		res.push_back(str[i] ^ key[i % keySize]);

	return res;
}
