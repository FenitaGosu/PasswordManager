#include <QAbstractItemModel>

#include "Interfaces/ICallBackPasswordPanel.h"

#include "PasswordPanelWidget.h"
#include "ui_PasswordPanelWidget.h"

using namespace PasswordUI;

PasswordPanelWidget::PasswordPanelWidget(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::PasswordPanelWidget())

{
	m_ui->setupUi(this);
}

PasswordPanelWidget::~PasswordPanelWidget() = default;

void PasswordPanelWidget::Setup(ICallBackPasswordPanel* callBack)
{
	m_callBack = callBack;
	SetupView();
}

void PasswordPanelWidget::Hide()
{
	hide();
}

void PasswordPanelWidget::Show()
{
	show();
}

void PasswordPanelWidget::Update()
{
	SetupView();
}

void PasswordPanelWidget::SetupView()
{
	m_model = m_callBack->GetShortDataModel();

	assert(m_model);

	m_ui->shortPasswordDataView->setModel(m_model);
}
