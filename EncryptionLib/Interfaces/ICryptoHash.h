#pragma once

#include <string>

namespace Encryption {

class ICryptoHash
{
public:
	virtual ~ICryptoHash() = default;
	virtual std::string GetMd5(const std::string& msg) const = 0;
};

}
