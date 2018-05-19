#pragma once

#include <vector>

#include <QString>

namespace PasswordKit {

/**
 * Provider settings interface for application
 */
class IApplicatonSettings
{
public:
	virtual ~IApplicatonSettings() = default;

	virtual QString GetOrganizationName() const = 0;
	virtual QString GetApplicationName() const = 0;
};

}
