#include <vector>

#include "Enums/ComponentsOfPassword.h"

#include "PasswordComponents.h"
#include "SimpleGenerator.h"

using namespace PasswordGenerator;

SimpleGenerator::SimpleGenerator()
	: m_components(std::make_unique<PasswordComponents>())
{
}

SimpleGenerator::~SimpleGenerator() = default;

std::vector<std::string> SimpleGenerator::Generate(const std::vector<СomponentsOfPassword>& settings, size_t length, size_t count) const
{
	return std::vector<std::string>();
}
