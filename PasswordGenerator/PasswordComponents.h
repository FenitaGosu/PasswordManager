#pragma once

#include <map>
#include <string>

#include "Enums/ComponentsOfPassword.h"

namespace PasswordGenerator {

struct PasswordComponents
{
	PasswordComponents()
		: components
		{
			{ ComponentsOfPassword::Numerals,		"0123456789" },
			{ ComponentsOfPassword::UpperCase,		"ABCDEFGHIJKLMNOPQRSTUVWXYZ" },
			{ ComponentsOfPassword::LowerCase,		"abcdefghijklmnopqrstuvwxyz" },
			{ ComponentsOfPassword::SpecialSymbols,	"!\"#$%&'()*+,-./:;<=>?@[]^_{|}~" }
		}
	{
	}

	const std::map<ComponentsOfPassword, std::string> components;
};

}
