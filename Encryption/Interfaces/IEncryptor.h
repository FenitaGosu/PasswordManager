#pragma once

#include <string>

namespace Encryption {

class IEncryptor
{
public:
	virtual ~IEncryptor() = default;

	virtual std::string Encrypt(const std::string& msg) const = 0;
	virtual std::string Decrypt(const std::string& encryptedMsg) const = 0;
};

}
