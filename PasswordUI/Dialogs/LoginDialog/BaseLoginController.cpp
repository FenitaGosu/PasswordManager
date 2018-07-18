#include "ILoginDialog.h"
#include "ui_LoginDialog.h"

#include "BaseLoginController.h"

using namespace PasswordUI;

BaseLoginController::BaseLoginController(PasswordLogic::ICredentialsInspector* const inspector, ILoginDialog* const dialog)
	: m_inspector(inspector)
	, m_dialog(dialog)
{
}

void BaseLoginController::SetDefaultNewPassword(const QString& password)
{
	m_dialog->GetUi()->newPasswordLineEdit->setText(password);
	m_dialog->GetUi()->repeatPasswordLineEdit->setText(password);
}

void BaseLoginController::Setup()
{
	connect(m_dialog->GetUi()->generateButton,	&QAbstractButton::clicked,			std::bind(&ILoginDialog::Generate, m_dialog));
	connect(m_dialog->GetUi()->cancelButton,	&QAbstractButton::clicked, this,	&BaseLoginController::OnCancelClicked);
	connect(m_dialog->GetUi()->saveButton,		&QAbstractButton::clicked, this,	&BaseLoginController::OnSaveClicked);
}
