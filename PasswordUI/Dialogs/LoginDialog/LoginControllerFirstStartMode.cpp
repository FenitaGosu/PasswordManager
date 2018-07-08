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
	connect(m_dialog->GetUi()->cancelButton,		&QAbstractButton::clicked, this, &LoginControllerFirstStartMode::OnCancelClicked);
	connect(m_dialog->GetUi()->saveButton,			&QAbstractButton::clicked, this, &LoginControllerFirstStartMode::OnSaveClicked);

	connect(m_dialog->GetUi()->passwordLineEdit, &QLineEdit::textChanged, [btn = m_dialog->GetUi()->okButton](const QString& text){ btn->setDisabled(text.isEmpty()); });

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
	m_inspector->SetPassword(m_dialog->GetUi()->newPasswordLineEdit->text().toStdString());
	m_dialog->Accept();
}

void LoginControllerFirstStartMode::OnCancelClicked()
{
	m_dialog->Reject();
}
