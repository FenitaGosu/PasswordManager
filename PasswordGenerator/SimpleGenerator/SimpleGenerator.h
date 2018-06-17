#pragma once

#include <memory>

#include "Interfaces/IPasswordGenerator.h"

namespace PasswordGenerator {

struct PasswordComponents;

class SimpleGenerator : public IPasswordGenerator
{
public:
	SimpleGenerator();
	~SimpleGenerator();

	std::vector<std::string> Generate(const std::vector<ComponentsOfPassword>& settings, size_t length, size_t count) const override;

private:
	std::unique_ptr<PasswordComponents> m_components;
};

}
