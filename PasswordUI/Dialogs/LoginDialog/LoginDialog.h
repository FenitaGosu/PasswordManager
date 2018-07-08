#pragma once

#include <QDialog>
#include <QScopedPointer>

#include "ILoginDialog.h"

namespace PasswordLogic {
class ICredentialsInspector;
}

namespace Ui {
class LoginDialog;
}

namespace PasswordUI {

class BaseLoginController;

class LoginDialog
		: public QDialog
		, public ILoginDialog
{
	Q_OBJECT

public:
	enum class Mode
	{
		Login = 0,
		SetPassword,
		FisrtStart
	};

public:
	explicit LoginDialog(Mode mode, PasswordLogic::ICredentialsInspector* const credentialsInspector, QWidget* parent = nullptr);
	~LoginDialog();

	void Reject() override;
	void Accept() override;
	Ui::LoginDialog* GetUi() const noexcept override;

private:
	std::unique_ptr<BaseLoginController> CreateController(Mode mode, ILoginDialog* loginDialog, PasswordLogic::ICredentialsInspector* credentialsInspector) const;

private:
	QScopedPointer<Ui::LoginDialog> m_ui;
	std::unique_ptr<BaseLoginController> m_controller;
};

}
