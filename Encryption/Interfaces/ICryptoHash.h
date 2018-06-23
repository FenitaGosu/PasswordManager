#pragma once

#include <string>

namespace Encryption {

class ICryptoHash
{
public:
	virtual ~ICryptoHash() = default;

	virtual std::string GetMd5(const std::string& msg) const = 0;
	virtual std::string GetSha2_256(const std::string& msg) const = 0;
	virtual std::string GetSha3_256(const std::string& msg) const = 0;
};

}
