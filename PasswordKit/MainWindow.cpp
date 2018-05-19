#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace PasswordKit;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);
}

MainWindow::~MainWindow() = default;
