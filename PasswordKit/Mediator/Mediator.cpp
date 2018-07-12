#include <QDialog>
#include <QMainWindow>
#include <QPointer>

#include "Application/Application.h"

#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "PasswordUI/Dialogs/PasswordGeneratorDialog.h"
#include "PasswordUI/Dialogs/AboutDialog.h"
#include "PasswordUI/Dialogs//LoginDialog/LoginDialog.h"

#include "Mediator.h"

using namespace PasswordKit;
using namespace PasswordUI;

Mediator::Mediator(std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialsInspector, QObject* parent)
	: QObject(parent)
	, m_credentialsInspector(std::move(credentialsInspector))
{
}

bool Mediator::ShowLoginDialog()
{
	LoginDialog loginDialog(m_credentialsInspector->IsNeedSetPassword() ? LoginDialog::Mode::FisrtStart : LoginDialog::Mode::Login,
							m_credentialsInspector.get());
	return static_cast<bool>(loginDialog.exec());
}

void PasswordKit::Mediator::OnShowAbout()
{
	AboutDialog aboutDialog(GetApp->GetMainWindow());
	aboutDialog.exec();
}

void Mediator::OnShowIndependentPasswordGeneratorDialog()
{
	PasswordGeneratorDialog d(PasswordGeneratorDialog::Mode::Independent, GetApp->GetMainWindow());
	d.exec();
}

void Mediator::OnShowEmbeddablePasswordGeneratorDialog(QString& pas)
{
	PasswordGeneratorDialog d(PasswordGeneratorDialog::Mode::Embeddable, GetApp->GetMainWindow());
	if (d.exec())
		pas = d.GetPassowrd();
}

void Mediator::OnShowSetMainPasswordDialog()
{
	LoginDialog loginDialog(LoginDialog::Mode::SetPassword, m_credentialsInspector.get());
	loginDialog.exec();
}
