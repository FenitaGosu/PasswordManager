#pragma once

namespace PasswordUI {

class ICentralView
{
public:
	enum class Mode
	{
		AddNewAccount = 0,
		ViewAccount,
	};

public:
	virtual ~ICentralView() = default;

	virtual void ActivateMode(Mode mode) = 0;
};

}
