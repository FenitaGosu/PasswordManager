#pragma once
#include <QString>

namespace Ui {
class LoginDialog;
}

namespace PasswordUI {

class ILoginDialog
{
public:
	virtual ~ILoginDialog() = default;

	virtual void Reject() = 0;
	virtual void Accept() = 0;
	virtual Ui::LoginDialog* GetUi() const noexcept = 0;

public:
	inline const static QString INCORRECT_PASSWORD = "Incorrect password.";
	inline const static QString INCORRECT_OLD_PASSWORD = "Incorrect old password.";

};

}
