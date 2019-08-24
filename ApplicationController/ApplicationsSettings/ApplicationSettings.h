#pragma once

#include <memory>
#include <string>
#include <map>

#include "ApplicationController/Enums/Action.h"
#include "ApplicationController/Interfaces/IApplicationSettings.h"

namespace Tools {
class Same;
}

namespace Controller {

class ApplicationSettings : public IApplicationSettings
{
public:
	ApplicationSettings(const std::map<std::string, Tools::Same>& values);
	~ApplicationSettings();
	
	std::string GetMasterPassword() const override;
	std::string GetDataBasePath() const override;

	std::string GetAction() const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
