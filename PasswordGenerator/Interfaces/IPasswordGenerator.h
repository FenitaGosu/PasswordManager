#pragma once

#include <vector>
#include <string>

namespace PasswordGenerator {

enum class СomponentsOfPassword;

/**
 * Password generator interface
 */
class IPasswordGenerator
{
public:
	virtual ~IPasswordGenerator() = default;
	virtual std::vector<std::string> Generate(const std::vector<СomponentsOfPassword>& settings, size_t length, size_t count) const = 0;
};

}
