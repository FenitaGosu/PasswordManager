#pragma once

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui {
class MainWindow;
}

namespace PasswordKit {

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	QScopedPointer<Ui::MainWindow> m_ui;
};

}
