#pragma once


namespace PasswordUI {

class IPasswordPanel
{
public:
	virtual ~IPasswordPanel() = default;

	virtual void Hide() = 0;
	virtual void Show() = 0;
	virtual void Update() = 0;
};

}
