#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#include <random>
#include <stdexcept>

#include "ToolsLib/Random/RandomIntGenerator.h"

#include "PasswordGeneratorLib/Enums/ComponentsOfPassword.h"
#include "PasswordGeneratorLib/PasswordComponents.h"

#include "SimpleGenerator.h"

using namespace PasswordGenerator;

namespace {

std::string& shuffle(std::string& str)
{
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(str.begin(), str.end(), g);

	return str;
}

}

SimpleGenerator::SimpleGenerator()
	: m_components(std::make_unique<PasswordComponents>())
{
}

SimpleGenerator::~SimpleGenerator() = default;

std::vector<std::string> SimpleGenerator::Generate(const std::vector<ComponentsOfPassword>& settings, size_t length, size_t count) const
{
	if (settings.size() > length)
		throw std::invalid_argument("length must be >= settings.size()");

	Tools::RandomIntGenerator<size_t> genInt;
	std::vector<std::string> res;
	res.reserve(count);

	const auto generate = [&genInt, &settings, length, &comp = m_components]() -> std::string
	{
		std::string res;
		res.reserve(length);

		const auto addSymbol = [&res, &genInt, &comp](auto conponentsType)
		{
			const auto it = comp->components.find(conponentsType);
			assert(it != comp->components.cend());

			genInt.SetParams(0, it->second.size() - 1);
			res += it->second[genInt.Get()];
		};

		std::for_each(settings.cbegin(), settings.cend(), addSymbol);

		for (size_t i = 0, sz = length - settings.size(); i < sz; ++i)
		{
			genInt.SetParams(0, settings.size() - 1);
			addSymbol(settings[genInt.Get()]);
		}

		assert(res.size() == length);

		return shuffle(res);
	};

	std::generate_n(std::back_inserter(res), count, generate);

	return res;
}
