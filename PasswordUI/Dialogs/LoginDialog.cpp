#include "LoginDialog.h"
#include "ui_LoginDialog.h"

using namespace PasswordUI;

LoginDialog::LoginDialog(QWidget* parent)
	: QDialog(parent)
	, m_ui(new Ui::LoginDialog())
{
	m_ui->setupUi(this);
	setWindowFlags (windowFlags() | Qt::FramelessWindowHint);

	connect(m_ui->okButton,				&QAbstractButton::clicked, this, &LoginDialog::OnOkClicked);
	connect(m_ui->exitButton,			&QAbstractButton::clicked, this, &LoginDialog::OnExitClicked);
	connect(m_ui->saveButton,			&QAbstractButton::clicked, this, &LoginDialog::OnSaveClicked);
	connect(m_ui->cancelButton,			&QAbstractButton::clicked, this, &LoginDialog::OnCancelClicked);
	connect(m_ui->newPasswordButton,	&QAbstractButton::clicked, this, &LoginDialog::OnNewPasswordClicked);
}

LoginDialog::~LoginDialog() = default;

void LoginDialog::OnOkClicked()
{
	emit accept();
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
