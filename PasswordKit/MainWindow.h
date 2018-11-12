#pragma once

#include <QMainWindow>
#include <QScopedPointer>
#include <QPointer>

namespace Ui {
class MainWindow;
}

namespace PasswordLogic {
class DataController;
}

namespace PasswordKit {

class Mediator;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(PasswordKit::Mediator* mediator, PasswordLogic::DataController *controller, QWidget *parent = nullptr);
	~MainWindow();

private:
	QScopedPointer<Ui::MainWindow> m_ui;
	Mediator* m_mediator;
};

}
