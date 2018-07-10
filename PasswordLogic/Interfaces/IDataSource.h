#pragma once

#include <string>

namespace PasswordLogic {

class IDataSource
{
public:
	virtual ~IDataSource() = default;

	virtual bool IsFisrstStart() const noexcept = 0;

	virtual std::string GeCurrentMainPassword() const = 0;
	virtual void SetCurrentMainPassword(const std::string& password) = 0;
};

}
