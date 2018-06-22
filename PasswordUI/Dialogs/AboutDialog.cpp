#include "AboutDialog.h"
#include "ui_AboutDialog.h"

using namespace PasswordUI;

AboutDialog::AboutDialog(QWidget* parent)
	: QDialog(parent)
	, m_ui(new Ui::AboutDialog())
{
	m_ui->setupUi(this);

	setWindowFlags (windowFlags() | Qt::FramelessWindowHint);
}

AboutDialog::~AboutDialog() = default;

void AboutDialog::mousePressEvent(QMouseEvent* event)
{
	QDialog::mousePressEvent(event);
	emit accept();
}

void AboutDialog::keyPressEvent(QKeyEvent* event)
{
	QDialog::keyPressEvent(event);
	emit accept();
}
