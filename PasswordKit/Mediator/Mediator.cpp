#include <QDialog>
#include <QMainWindow>
#include <QPointer>

#include "Application/Application.h"

#include "PasswordUI/Dialogs/PasswordGeneratorDialog.h"

#include "Mediator.h"

using namespace PasswordKit;
using namespace PasswordUI;

Mediator::Mediator(QObject* parent)
	: QObject(parent)
{
}

void PasswordKit::Mediator::OnAboutClicked()
{
	QDialog aboutDialog(GetApp->GetMainWindow());
	aboutDialog.exec();
}

void Mediator::OnShowIndependentPasswordGeneratorDialog()
{
	PasswordGeneratorDialog d;
	d.exec();
}

void Mediator::OnShowEmbeddablePasswordGeneratorDialog(QString& pas)
{
	PasswordGeneratorDialog d(PasswordGeneratorDialog::Mode::Embeddable);
	if (d.exec())
		pas = d.GetPassowrd();
}
