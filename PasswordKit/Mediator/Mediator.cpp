#include <QDialog>
#include <QMainWindow>
#include <QPointer>

#include "Application/Application.h"

#include "PasswordUI/Dialogs/PasswordGeneratorDialog.h"
#include "PasswordUI/Dialogs/AboutDialog.h"
#include "PasswordUI/Dialogs/LoginDialog.h"

#include "Mediator.h"

using namespace PasswordKit;
using namespace PasswordUI;

Mediator::Mediator(QObject* parent)
	: QObject(parent)
{
}

bool Mediator::ShowLoginDialog()
{
	LoginDialog loginDialog;
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
