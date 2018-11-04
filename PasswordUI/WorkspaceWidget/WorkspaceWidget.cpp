#include "StateController/StateController.h"
#include "Event/Event.h"
#include "Enums/Tool.h"

#include "SystemConstants.h"

#include "WorkspaceWidget.h"
#include "ui_WorkspaceWidget.h"

using namespace PasswordUI;

WorkspaceWidget::WorkspaceWidget(QWidget* parent)
	: QWidget(parent)
	, m_ui(new Ui::WorkspaceWidget())
	, m_stateController(new StateController(this))
{
	m_ui->setupUi(this);

	m_stateController->Setup(m_ui->sidePanelWidget, m_ui->topPanelWidget);
	m_ui->sidePanelWidget->Setup(m_stateController);
	m_ui->topPanelWidget->Setup(m_stateController);

	m_stateController->HandleEvent(Event(EventType::ToolPanel, SystemConstants::ACTIVATE_TOOL, static_cast<int>(Tool::Passwords)));
}

WorkspaceWidget::~WorkspaceWidget() = default;
