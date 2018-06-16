#include <vector>
#include <algorithm>
#include <functional>

#include "Tools/Random/RandomIntGenerator.h"

#include "Enums/ComponentsOfPassword.h"

#include "PasswordComponents.h"
#include "SimpleGenerator.h"

using namespace PasswordGenerator;

SimpleGenerator::SimpleGenerator()
	: m_components(std::make_unique<PasswordComponents>())
{
}

SimpleGenerator::~SimpleGenerator() = default;

std::vector<std::string> SimpleGenerator::Generate(const std::vector<ComponentsOfPassword>& settings, size_t length, size_t count) const
{
	Tools::RandomIntGenerator genInt;
	std::vector<std::string> res;
	res.reserve(count);

	const auto generate = [&genInt, &settings, length]() -> std::string
	{
		return std::string();
	};


	std::generate_n(std::back_inserter(res), count, generate);

	return res;
}
