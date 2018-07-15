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
	inline const static QString INCORRECT_PASSWORD_LEGTH = "Password length must be more than 6 characters";

	inline constexpr static size_t MIN_PAS_LENGHT = 6;

};

}
