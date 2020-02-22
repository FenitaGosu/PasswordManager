#pragma once

#include <memory>

#include "EncryptionLib/Interfaces/IEncryptor.h"

namespace Encryption {

class IKeyProvider;

class XOREncryptor : public IEncryptor
{
public:
	XOREncryptor(std::unique_ptr<IKeyProvider>&& provider);
	~XOREncryptor();

	std::string Encrypt(const std::string& msg) const override;
	std::string Decrypt(const std::string& encryptedMsg) const override;

private:
	std::string Impl(const std::string& str) const;

private:
	std::unique_ptr<IKeyProvider> m_keyProvider;
};

}
