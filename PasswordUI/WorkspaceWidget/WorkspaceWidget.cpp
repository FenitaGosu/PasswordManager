#include "UIController/UIController.h"
#include "Event/Event.h"
#include "Enums/Tool.h"

#include "SystemConstants.h"

#include "WorkspaceWidget.h"
#include "ui_WorkspaceWidget.h"

using namespace PasswordUI;

WorkspaceWidget::WorkspaceWidget(QWidget* parent)
	: QWidget(parent)
	, m_ui(new Ui::WorkspaceWidget())
	, m_uiController( std::make_unique<UIController>())
{
	m_ui->setupUi(this);
}

WorkspaceWidget::~WorkspaceWidget() = default;

void WorkspaceWidget::Init(PasswordLogic::DataController* controller)
{
	m_uiController->Setup(controller, m_ui->sidePanelWidget, m_ui->topPanelWidget, m_ui->centralWidget);
	m_ui->sidePanelWidget->Setup(m_uiController.get());
	m_ui->topPanelWidget->Setup(m_uiController.get());
	m_ui->centralWidget->Setup(m_uiController.get(), m_uiController.get(), m_uiController.get());

	m_uiController->HandleEvent(Event(EventType::ToolsPanel, SystemConstants::ACTIVATE_TOOL, static_cast<int>(Tool::Accounts)));
}
