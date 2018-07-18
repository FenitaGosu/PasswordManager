#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "LoginControllerSetPasswordMode.h"

#include "ILoginDialog.h"
#include "ui_LoginDialog.h"

using namespace PasswordUI;

LoginControllerSetPasswordMode::LoginControllerSetPasswordMode(PasswordLogic::ICredentialsInspector* const inspector, ILoginDialog* const dialog)
	: BaseLoginController(inspector, dialog)
{
}

void LoginControllerSetPasswordMode::Setup()
{
	BaseLoginController::Setup();

	const auto checkEnableSaveNewPassword = [this](const QString&)
	{
		auto ui = m_dialog->GetUi();
		bool enableSave = !ui->oldPasswordLineEdit->text().isEmpty() && !ui->newPasswordLineEdit->text().isEmpty() && ui->newPasswordLineEdit->text() == ui->repeatPasswordLineEdit->text();
		ui->saveButton->setEnabled(enableSave);
	};

	connect(m_dialog->GetUi()->oldPasswordLineEdit,		&QLineEdit::textChanged, checkEnableSaveNewPassword);
	connect(m_dialog->GetUi()->newPasswordLineEdit,		&QLineEdit::textChanged, checkEnableSaveNewPassword);
	connect(m_dialog->GetUi()->repeatPasswordLineEdit,	&QLineEdit::textChanged, checkEnableSaveNewPassword);

	m_dialog->GetUi()->stackedWidget->setCurrentWidget(m_dialog->GetUi()->setPasswordPage);
	checkEnableSaveNewPassword(QString());
}

void LoginControllerSetPasswordMode::OnSaveClicked()
{
	m_dialog->GetUi()->errorLabel->clear();

	if (m_inspector->CheckPassword(m_dialog->GetUi()->oldPasswordLineEdit->text().toStdString()))
	{
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
	else
	{
		m_dialog->GetUi()->errorNewPasswordLabel->setText(ILoginDialog::INCORRECT_OLD_PASSWORD);
	}
}

void LoginControllerSetPasswordMode::OnCancelClicked()
{
	m_dialog->Reject();
}
