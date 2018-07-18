#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "LoginControllerLoginMode.h"

#include "ILoginDialog.h"
#include "ui_LoginDialog.h"

using namespace PasswordUI;

LoginControllerLoginMode::LoginControllerLoginMode(PasswordLogic::ICredentialsInspector* const inspector, ILoginDialog* const dialog)
	: BaseLoginController(inspector, dialog)
{
}

void LoginControllerLoginMode::Setup()
{
	BaseLoginController::Setup();

	connect(m_dialog->GetUi()->okButton,			&QAbstractButton::clicked, this, &LoginControllerLoginMode::OnOkClicked);
	connect(m_dialog->GetUi()->exitButton,			&QAbstractButton::clicked, this, &LoginControllerLoginMode::OnExitClicked);
	connect(m_dialog->GetUi()->newPasswordButton,	&QAbstractButton::clicked, this, &LoginControllerLoginMode::OnNewPasswordClicked);

	m_dialog->GetUi()->okButton->setDisabled(true);
	connect(m_dialog->GetUi()->passwordLineEdit, &QLineEdit::textChanged, [btn = m_dialog->GetUi()->okButton](const QString& text){ btn->setDisabled(text.isEmpty()); });

	const auto checkEnableSaveNewPassword = [this](const QString&)
	{
		auto ui = m_dialog->GetUi();
		bool enableSave = !ui->oldPasswordLineEdit->text().isEmpty() && !ui->newPasswordLineEdit->text().isEmpty() && ui->newPasswordLineEdit->text() == ui->repeatPasswordLineEdit->text();
		ui->saveButton->setEnabled(enableSave);
	};

	connect(m_dialog->GetUi()->oldPasswordLineEdit,		&QLineEdit::textChanged, checkEnableSaveNewPassword);
	connect(m_dialog->GetUi()->newPasswordLineEdit,		&QLineEdit::textChanged, checkEnableSaveNewPassword);
	connect(m_dialog->GetUi()->repeatPasswordLineEdit,	&QLineEdit::textChanged, checkEnableSaveNewPassword);

	checkEnableSaveNewPassword(QString());
}

void LoginControllerLoginMode::OnOkClicked()
{
	if (m_inspector->CheckPassword(m_dialog->GetUi()->passwordLineEdit->text().toStdString()))
		m_dialog->Accept();
	else
		m_dialog->GetUi()->errorLabel->setText(ILoginDialog::INCORRECT_PASSWORD);
}

void LoginControllerLoginMode::OnExitClicked()
{
	m_dialog->Reject();
}

void LoginControllerLoginMode::OnSaveClicked()
{
		m_dialog->GetUi()->errorLabel->clear();
	if (m_inspector->CheckPassword(m_dialog->GetUi()->oldPasswordLineEdit->text().toStdString()))
	{
		m_inspector->SetPassword(m_dialog->GetUi()->newPasswordLineEdit->text().toStdString());
		m_dialog->Accept();
	}
	else
	{
		m_dialog->GetUi()->errorNewPasswordLabel->setText(ILoginDialog::INCORRECT_OLD_PASSWORD);
	}
}

void LoginControllerLoginMode::OnCancelClicked()
{
	m_dialog->GetUi()->stackedWidget->setCurrentWidget(m_dialog->GetUi()->loginPage);
}

void LoginControllerLoginMode::OnNewPasswordClicked()
{
	m_dialog->GetUi()->stackedWidget->setCurrentWidget(m_dialog->GetUi()->setPasswordPage);
}
