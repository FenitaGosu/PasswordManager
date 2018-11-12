#include <QDialog>
#include <QMainWindow>
#include <QPointer>

#include "Application/Application.h"

#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "PasswordUI/Dialogs/PasswordGeneratorDialog.h"
#include "PasswordUI/Dialogs/AboutDialog.h"
#include "PasswordUI/Dialogs//LoginDialog/LoginDialog.h"

#include "PasswordUI/Interfaces/IObjectsConnector.h"

#include "Mediator.h"

using namespace PasswordKit;
using namespace PasswordUI;

Mediator::Mediator(PasswordLogic::ICredentialsInspector* credentialsInspector, QObject* parent)
	: QObject(parent)
	, m_credentialsInspector(credentialsInspector)
{
	ObjectsConnector::RegisterReceiver(IObjectsConnector::GENERATE_PASSWORD, this, SLOT(OnShowEmbeddablePasswordGeneratorDialog(QString&, size_t)));
}

bool Mediator::ShowLoginDialog()
{
	LoginDialog loginDialog(m_credentialsInspector->IsNeedSetPassword() ? LoginDialog::Mode::FisrtStart : LoginDialog::Mode::Login,
							m_credentialsInspector);
	return loginDialog.Exec();
}

void PasswordKit::Mediator::OnShowAbout()
{
	AboutDialog aboutDialog(GetApp->GetMainWindow());
	aboutDialog.exec();
}

void Mediator::OnShowIndependentPasswordGeneratorDialog()
{
	PasswordGeneratorDialog d(PasswordGeneratorDialog::Mode::Independent, 0, GetApp->GetMainWindow());
	d.exec();
}

void Mediator::OnShowEmbeddablePasswordGeneratorDialog(QString& pas, size_t minLenght)
{
	PasswordGeneratorDialog d(PasswordGeneratorDialog::Mode::Embeddable, minLenght, GetApp->GetMainWindow());
	if (d.exec())
		pas = d.GetPassowrd();
}

void Mediator::OnShowSetMainPasswordDialog()
{
	LoginDialog loginDialog(LoginDialog::Mode::SetPassword, m_credentialsInspector);
	loginDialog.Exec();
}
