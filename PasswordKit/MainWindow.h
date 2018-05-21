#pragma once

#include <QMainWindow>
#include <QScopedPointer>
#include <QPointer>

namespace Ui {
class MainWindow;
}

namespace PasswordKit {

class Mediator;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QPointer<Mediator> mediator, QWidget *parent = nullptr);
	~MainWindow();

private:
	QScopedPointer<Ui::MainWindow> m_ui;
	QPointer<Mediator> m_mediator;
};

}
