#pragma once

#include "EncryptionLib/Interfaces/ICryptoHash.h"

namespace Encryption {

class CryptoHashQt : public ICryptoHash
{
public:
	std::string GetMd5(const std::string& msg) const override;
	std::string GetSha2_256(const std::string& msg) const override;
	std::string GetSha3_256(const std::string& msg) const override;
};

}
