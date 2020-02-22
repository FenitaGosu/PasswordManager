#pragma once

#include <vector>
#include <string>

namespace PasswordGenerator {

enum class ComponentsOfPassword;

/**
 * Password generator interface
 */
class IPasswordGenerator
{
public:
	virtual ~IPasswordGenerator() = default;
	virtual std::vector<std::string> Generate(const std::vector<ComponentsOfPassword>& settings, size_t length, size_t count) const = 0;
};

}
