#pragma once

#include <map>
#include <string>

#include "Enums/ComponentsOfPassword.h"

namespace PasswordGenerator {

struct PasswordComponents
{
	PasswordComponents()
	{
		components =
		{
			{ СomponentsOfPassword::Numerals,		"0123456789" },
			{ СomponentsOfPassword::UpperCase,		"ABCDEFGHIJKLMNOPQRSTUVWXYZ" },
			{ СomponentsOfPassword::LowerCase,		"abcdefghijklmnopqrstuvwxyz" },
			{ СomponentsOfPassword::SpecialSymbols,	"!\"#$%&'()*+,-./:;<=>?@[]^_{|}~" }
		};
	}

	std::map<СomponentsOfPassword, std::string> components;
};

}
