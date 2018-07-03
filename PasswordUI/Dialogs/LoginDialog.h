#pragma once

#include <QDialog>
#include <QScopedPointer>

namespace PasswordLogic {
class ICredentialsInspector;
}

namespace Ui {
class LoginDialog;
}

namespace PasswordUI {

class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	explicit LoginDialog(const PasswordLogic::ICredentialsInspector* credentialsInspector, QWidget* parent = nullptr);
	~LoginDialog();

private:
	void OnOkClicked();
	void OnExitClicked();
	void OnSaveClicked();
	void OnCancelClicked();
	void OnNewPasswordClicked();

private:
	QScopedPointer<Ui::LoginDialog> m_ui;

	const PasswordLogic::ICredentialsInspector* m_inspector;
};

}
