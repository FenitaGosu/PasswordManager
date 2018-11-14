#pragma once

#include "Interfaces/IEncryptor.h"

namespace Encryption {

class EmptyEncryptor : public IEncryptor
{
public:
	std::string Encrypt(const std::string& msg) const override;
	std::string Decrypt(const std::string& encryptedMsg) const override;
};

}
