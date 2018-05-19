#pragma once

#include <memory>

#include "Interfaces/IApplicationSettings.h"

namespace JsonTools{
class IParserJson;
}

namespace PasswordKit {

/**
 * Json implementation of the interface IApplicatonSettings
 */
class ApplicatonSettingsJsonImpl : public IApplicatonSettings
{
public:
	ApplicatonSettingsJsonImpl();
	~ApplicatonSettingsJsonImpl();

	QString GetOrganizationName() const override;
	QString GetApplicationName() const override;

private:
	std::unique_ptr<JsonTools::IParserJson> m_parser;
};

}
