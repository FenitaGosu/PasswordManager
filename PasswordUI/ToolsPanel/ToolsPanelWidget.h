#pragma once

#include <QFrame>
#include <QScopedPointer>

#include "Interfaces/IToolsPanel.h"

namespace Ui {
class ToolsPanelWidget;
}

class QAbstractItemModel;
class QButtonGroup;

namespace PasswordUI {

class ICallBackToolPanel;

class ToolsPanelWidget : public QFrame, public IToolsPanel
{
	Q_OBJECT

public:
	explicit ToolsPanelWidget(QWidget* parent = nullptr);
	~ToolsPanelWidget();

	void Setup(ICallBackToolPanel *callBack);

	/// IToolsPanel
	void ActivateTool(Tool tool) override;
	Tool GetActiveTool() const override;

private:
	void SetupView();

private:
	QScopedPointer<Ui::ToolsPanelWidget> m_ui;

	ICallBackToolPanel* m_callBack;
	QAbstractItemModel* m_model;
	QButtonGroup* m_btnGroup;
};

}

