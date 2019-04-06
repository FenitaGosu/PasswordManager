#pragma once

#include <memory>
#include <string>
#include <map>

#include "Interfaces/IApplicationSettings.h"

namespace Tools {
class Same;
}

namespace PasswordKit {

class ApplicationSettings : public IApplicationSettings
{
public:
	ApplicationSettings(const std::map<std::string, Tools::Same>& values);
	~ApplicationSettings();

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}