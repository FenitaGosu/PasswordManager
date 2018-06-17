#include <algorithm>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PasswordGenerator/SimpleGenerator/SimpleGenerator.h"
#include "PasswordGenerator/Enums/ComponentsOfPassword.h"
#include "PasswordGenerator/PasswordComponents.h"

using namespace PasswordGenerator;

TEST(SimpleGeneratorTest, ThrowExep)
{
	SimpleGenerator g;
	ASSERT_ANY_THROW(g.Generate({ ComponentsOfPassword::Numerals, ComponentsOfPassword::UpperCase, ComponentsOfPassword::LowerCase, ComponentsOfPassword::SpecialSymbols },
								1, 1));
}

TEST(SimpleGeneratorTest, NoThrowExep)
{
	SimpleGenerator g;
	ASSERT_NO_THROW(g.Generate({ ComponentsOfPassword::Numerals, ComponentsOfPassword::UpperCase, ComponentsOfPassword::LowerCase, ComponentsOfPassword::SpecialSymbols },
								4, 1));
}

TEST(SimpleGeneratorTest, CountValid)
{
	SimpleGenerator g;
	ASSERT_EQ(g.Generate({ ComponentsOfPassword::Numerals, ComponentsOfPassword::UpperCase, ComponentsOfPassword::LowerCase, ComponentsOfPassword::SpecialSymbols },
						4, 10).size(), 10);
}

TEST(SimpleGeneratorTest, LengthValid)
{
	SimpleGenerator g;
	const auto res = g.Generate({ ComponentsOfPassword::Numerals, ComponentsOfPassword::UpperCase, ComponentsOfPassword::LowerCase, ComponentsOfPassword::SpecialSymbols },
								10, 10);
	bool value = std::any_of(res.cbegin(), res.cend(), [](const auto& item){ return item.size() == 10; });
	ASSERT_EQ(value, true);
}

TEST(SimpleGeneratorTest, ComponentsContainsValid)
{
	SimpleGenerator g;
	auto res = g.Generate({ ComponentsOfPassword::UpperCase, ComponentsOfPassword::SpecialSymbols }, 20, 1)[0];

	std::sort(res.begin(), res.end());

	std::map<ComponentsOfPassword, std::string> sortedComponents;

	PasswordComponents source;
	for(const auto& comp : source.components)
	{
		std::string sorted = comp.second;
		std::sort(sorted.begin(), sorted.end());
		sortedComponents.emplace(comp.first, sorted);
	}

	const auto& upperCase = sortedComponents[ComponentsOfPassword::UpperCase];
	const auto& specialSymbols = sortedComponents[ComponentsOfPassword::SpecialSymbols];
	const auto& lowerCase = sortedComponents[ComponentsOfPassword::LowerCase];
	const auto& numerals = sortedComponents[ComponentsOfPassword::Numerals];

	std::string upperCaseIntersection;
	std::set_intersection(res.cbegin(), res.cend(), upperCase.cbegin(), upperCase.cend(), std::back_inserter(upperCaseIntersection));

	std::string specialSymbolsIntersection;
	std::set_intersection(res.cbegin(), res.cend(), specialSymbols.cbegin(), specialSymbols.cend(), std::back_inserter(specialSymbolsIntersection));

	std::string lowerCaseIntersection;
	std::set_intersection(res.cbegin(), res.cend(), lowerCase.cbegin(), lowerCase.cend(), std::back_inserter(lowerCaseIntersection));

	std::string numeralsIntersection;
	std::set_intersection(res.cbegin(), res.cend(), numerals.cbegin(), numerals.cend(), std::back_inserter(numeralsIntersection));

	ASSERT_EQ(upperCaseIntersection.size() > 1, true);
	ASSERT_EQ(specialSymbolsIntersection.size() > 1, true);
	ASSERT_EQ(lowerCaseIntersection.empty(), true);
	ASSERT_EQ(numeralsIntersection.empty(), true);
}
