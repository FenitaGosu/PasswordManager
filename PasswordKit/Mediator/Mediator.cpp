#include <QDialog>
#include <QMainWindow>
#include <QPointer>

#include "Application/Application.h"

#include "Mediator.h"

using namespace PasswordKit;

Mediator::Mediator(QObject* parent)
	: QObject(parent)
{
}

void PasswordKit::Mediator::OnAboutClicked()
{
	QDialog aboutDialog(GetApp->GetMainWindow());
	aboutDialog.exec();
}
