#include <cassert>

#include <QAbstractItemModel>
#include <QToolButton>
#include <QButtonGroup>

#include "Event/Event.h"

#include "Enums/Tool.h"

#include "Interfaces/ICallBackToolPanel.h"

#include "ModelRoles/ModelToolRoles.h"

#include "SystemConstants.h"

#include "ToolPanelWidget.h"

#include "ui_ToolPanelWidget.h"

using namespace PasswordUI;

ToolPanelWidget::ToolPanelWidget(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::ToolPanelWidget())
{
	m_ui->setupUi(this);
}

void ToolPanelWidget::ActivateTool(Tool tool)
{
	m_btnGroup->button(static_cast<int>(tool))->setChecked(true);
}

Tool ToolPanelWidget::GetActiveTool() const
{
	return static_cast<Tool>(m_btnGroup->checkedId());
}

ToolPanelWidget::~ToolPanelWidget() = default;

void ToolPanelWidget::Setup(ICallBackToolPanel* callBack)
{
	m_callBack = callBack;
	SetupView();
}

void ToolPanelWidget::SetupView()
{
	m_model = m_callBack->GetInstrumentsModel();

	assert(m_model && m_model->rowCount() != 0);

	m_btnGroup = new QButtonGroup(this);

	for (int i = 0, sz = m_model->rowCount(); i < sz; ++i)
	{
		QAbstractButton* btn = nullptr;
		const auto index = m_model->index(i, 0);

		const auto tool = static_cast<Tool>(m_model->data(index, static_cast<int>(ModelToolRoles::Type)).toInt());
		const auto name = m_model->data(index, static_cast<int>(ModelToolRoles::Name)).toString();

		btn = new QToolButton(this);
		btn->setText(name);
		btn->setCheckable(true);

		m_btnGroup->addButton(btn, static_cast<int>(tool));

		m_ui->buttonLayout->addWidget(btn);
	}

	connect(m_btnGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), [callback = m_callBack](int tool)
	{
		callback->HandleEvent(Event(EventType::ToolPanel, SystemConstants::ACTIVATE_TOOL, (tool)));
	});
}
