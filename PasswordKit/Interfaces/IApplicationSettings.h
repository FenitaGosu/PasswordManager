#pragma once

#include <string>

namespace PasswordKit {

class IApplicationSettings
{
public:
	inline static const std::string KEY_DATABASE_PATH				= "database";
	inline static const std::string DESCRIPTION_KEY_DATABASE_PATH	= "Path to database.";

public:
	virtual ~IApplicationSettings() = default;
	virtual std::string GetDataBasePath() const = 0;
};

}
