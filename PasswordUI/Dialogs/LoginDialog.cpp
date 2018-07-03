#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "LoginDialog.h"
#include "ui_LoginDialog.h"

using namespace PasswordUI;

namespace {
const QString INCORRECT_PASSWORD = "Incorrect password.";
}

LoginDialog::LoginDialog(const PasswordLogic::ICredentialsInspector* credentialsInspector, QWidget* parent)
	: QDialog(parent)
	, m_ui(new Ui::LoginDialog())
	, m_inspector(credentialsInspector)
{
	m_ui->setupUi(this);
	setWindowFlags (windowFlags() | Qt::FramelessWindowHint);

	connect(m_ui->okButton,				&QAbstractButton::clicked, this, &LoginDialog::OnOkClicked);
	connect(m_ui->exitButton,			&QAbstractButton::clicked, this, &LoginDialog::OnExitClicked);
	connect(m_ui->saveButton,			&QAbstractButton::clicked, this, &LoginDialog::OnSaveClicked);
	connect(m_ui->cancelButton,			&QAbstractButton::clicked, this, &LoginDialog::OnCancelClicked);
	connect(m_ui->newPasswordButton,	&QAbstractButton::clicked, this, &LoginDialog::OnNewPasswordClicked);

	m_ui->okButton->setDisabled(true);
	connect(m_ui->passwordLineEdit, &QLineEdit::textChanged, [btn = m_ui->okButton](const QString& text){ btn->setDisabled(text.isEmpty()); });
}

LoginDialog::~LoginDialog() = default;

void LoginDialog::OnOkClicked()
{
	if (m_inspector->CheckPassword(m_ui->passwordLineEdit->text().toStdString()))
		emit accept();
	else
		m_ui->errorLabel->setText(INCORRECT_PASSWORD);
}

void LoginDialog::OnExitClicked()
{
	emit reject();
}

void LoginDialog::OnSaveClicked()
{
	m_ui->stackedWidget->setCurrentWidget(m_ui->loginPage);
}

void LoginDialog::OnCancelClicked()
{
	m_ui->stackedWidget->setCurrentWidget(m_ui->loginPage);
}

void LoginDialog::OnNewPasswordClicked()
{
	m_ui->stackedWidget->setCurrentWidget(m_ui->setPasswordPage);
}
