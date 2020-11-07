#pragma once

#include "EncryptionLib/Interfaces/ICryptoHash.h"

namespace Encryption {

class CryptoHash : public ICryptoHash
{
public:
	std::string GetMd5(const std::string& msg) const override;
};

}
