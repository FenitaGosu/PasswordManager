#pragma once

#include <QFrame>
#include <QScopedPointer>

#include "Interfaces/IToolPanel.h"

namespace Ui {
class ToolPanelWidget;
}

class QAbstractItemModel;
class QButtonGroup;

namespace PasswordUI {

class ICallBackToolPanel;

class ToolPanelWidget : public QFrame, public IToolPanel
{
	Q_OBJECT

public:
	explicit ToolPanelWidget(QWidget* parent = nullptr);
	~ToolPanelWidget();

	void Setup(ICallBackToolPanel *callBack);

	/// IToolPanel
	void ActivateTool(Tool tool) override;
	Tool GetActiveTool() const override;

private:
	void SetupView();

private:
	QScopedPointer<Ui::ToolPanelWidget> m_ui;

	ICallBackToolPanel* m_callBack;
	QAbstractItemModel* m_model;
	QButtonGroup* m_btnGroup;
};

}

