#pragma once

#include <memory>

#include <QWidget>
#include <QScopedPointer>

namespace Ui {
class WorkspaceWidget;
}

namespace PasswordLogic {
class DataController;
}

namespace PasswordUI {

class UIController;

class WorkspaceWidget : public QWidget
{
	Q_OBJECT

public:
	explicit WorkspaceWidget(QWidget* parent = nullptr);
	~WorkspaceWidget();

	void Init(PasswordLogic::DataController* controller);

private:
	QScopedPointer<Ui::WorkspaceWidget> m_ui;

	std::unique_ptr<UIController> m_uiController;
};

}
