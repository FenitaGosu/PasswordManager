#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "LoginControllerFirstStartMode.h"

#include "ILoginDialog.h"
#include "ui_LoginDialog.h"

using namespace PasswordUI;

LoginControllerFirstStartMode::LoginControllerFirstStartMode(PasswordLogic::ICredentialsInspector* const inspector, ILoginDialog* const dialog)
	: BaseLoginController(inspector, dialog)
{
}

void LoginControllerFirstStartMode::Setup()
{
	BaseLoginController::Setup();

	const auto checkEnableSaveNewPassword = [this](const QString&)
	{
		auto ui = m_dialog->GetUi();
		bool enableSave = !ui->newPasswordLineEdit->text().isEmpty() && ui->newPasswordLineEdit->text() == ui->repeatPasswordLineEdit->text();
		ui->saveButton->setEnabled(enableSave);
	};

	connect(m_dialog->GetUi()->newPasswordLineEdit,		&QLineEdit::textChanged, checkEnableSaveNewPassword);
	connect(m_dialog->GetUi()->repeatPasswordLineEdit,	&QLineEdit::textChanged, checkEnableSaveNewPassword);

	checkEnableSaveNewPassword(QString());

	m_dialog->GetUi()->stackedWidget->setCurrentWidget(m_dialog->GetUi()->setPasswordPage);
	m_dialog->GetUi()->oldPasswordFrame->setVisible(false);
}

void LoginControllerFirstStartMode::OnSaveClicked()
{
	m_dialog->GetUi()->errorLabel->clear();
	if (const auto pass = m_dialog->GetUi()->newPasswordLineEdit->text().toStdString(); pass.size() >= ILoginDialog::MIN_PAS_LENGHT)
	{
		m_inspector->SetPassword(pass);
		m_dialog->Accept();
	}
	else
	{
		m_dialog->GetUi()->errorNewPasswordLabel->setText(ILoginDialog::INCORRECT_PASSWORD_LEGTH);
	}
}

void LoginControllerFirstStartMode::OnCancelClicked()
{
	m_dialog->Reject();
}
