#pragma once

#include <map>
#include <vector>
#include <string>

namespace Tools {
class Same;
}

namespace PasswordLogic {
using Data		= std::map<std::string, Tools::Same>;
using DataList	= std::vector<Data>;
}
