#pragma once

#include <memory>
#include <string>
#include <map>

#include "ApplicationControllerLib/Interfaces/IApplicationSettings.h"

namespace Tools {
class Same;
}

namespace PasswordKit {

class ApplicationSettings : public Controller::IApplicationSettings
{
public:
	ApplicationSettings(const std::map<std::string, Tools::Same>& values);
	~ApplicationSettings();
	
	std::string GetDataBasePath() const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
