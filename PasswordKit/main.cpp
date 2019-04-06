#include <memory>
#include <execution>
#include <iostream>
#include <cstdlib>


#include "Mediator/Mediator.h"

namespace {
const std::string DATA_SOURCE_NAME = "/PasswordManager.db";
}

int main(int argc, char *argv[])
{
	try
	{
		const auto mediator = std::make_unique<PasswordKit::Mediator>(argc, argv);
		return 0;
	}
	catch(std::exception& exp)
	{
		std::cerr << exp.what();
		return EXIT_FAILURE;
	}
}
