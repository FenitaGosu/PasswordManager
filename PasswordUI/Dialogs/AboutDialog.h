#pragma once

#include <QDialog>
#include <QScopedPointer>

namespace Ui {
class AboutDialog;
}

class QMouseEvent;
class QKeyEvent;

namespace PasswordUI {

class AboutDialog : public QDialog
{
	Q_OBJECT

public:
	explicit AboutDialog(QWidget* parent = nullptr);
	~AboutDialog();

	void mousePressEvent(QMouseEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;

private:
	QScopedPointer<Ui::AboutDialog> m_ui;
};

}
