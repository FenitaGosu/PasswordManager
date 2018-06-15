#pragma once

#include "Interfaces/IPasswordGenerator.h"

namespace PasswordGenerator {

class SimpleGenerator : public IPasswordGenerator
{
public:
	std::vector<std::string> Generate(const std::vector<СomponentsOfPassword>& settings, size_t length, size_t count) const override;
};

}
