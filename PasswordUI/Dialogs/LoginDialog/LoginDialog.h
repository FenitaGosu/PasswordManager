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

class QString;

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

	bool Exec();

	void Reject() override;
	void Accept() override;
	void Generate() override;
	Ui::LoginDialog* GetUi() const noexcept override;

signals:
	void generatePassword(QString& pas, size_t minLenght);

private:
	std::unique_ptr<BaseLoginController> CreateController(Mode mode, ILoginDialog* loginDialog, PasswordLogic::ICredentialsInspector* credentialsInspector) const;

private:
	QScopedPointer<Ui::LoginDialog> m_ui;
	std::unique_ptr<BaseLoginController> m_controller;
	bool m_needGeneratePassword;
};

}
