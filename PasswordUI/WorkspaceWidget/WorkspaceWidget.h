#pragma once

#include <QWidget>
#include <QScopedPointer>
#include <QPointer>

namespace Ui {
class WorkspaceWidget;
}

namespace PasswordUI {

class StateController;

class WorkspaceWidget : public QWidget
{
	Q_OBJECT

public:
	explicit WorkspaceWidget(QWidget* parent = nullptr);
	~WorkspaceWidget();

private:
	QScopedPointer<Ui::WorkspaceWidget> m_ui;

	QPointer<StateController> m_stateController;
};

}
