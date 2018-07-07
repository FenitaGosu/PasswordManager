#include "Mediator/Mediator.h"

#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace PasswordKit;

MainWindow::MainWindow(QPointer<Mediator> mediator, QWidget *parent)
	: QMainWindow(parent)
	, m_ui(new Ui::MainWindow)
	, m_mediator(mediator)
{
	m_ui->setupUi(this);

	connect(m_ui->actionExit_,				&QAction::triggered, this,			&QMainWindow::close);
	connect(m_ui->actionAbout,				&QAction::triggered, m_mediator,	&Mediator::OnShowAbout);
	connect(m_ui->actionGeneratePassword,	&QAction::triggered, m_mediator,	&Mediator::OnShowIndependentPasswordGeneratorDialog);
	connect(m_ui->actionSetPassword,		&QAction::triggered, m_mediator,	&Mediator::OnShowSetMainPasswordDialog);
}

MainWindow::~MainWindow() = default;
