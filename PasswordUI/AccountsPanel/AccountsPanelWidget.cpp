#include <QAbstractItemModel>

#include "Interfaces/ICallBackPasswordPanel.h"

#include "AccountsPanelWidget.h"
#include "ui_AccountsPanelWidget.h"

using namespace PasswordUI;

AccountsPanelWidget::AccountsPanelWidget(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::AccountsPanelWidget())

{
	m_ui->setupUi(this);
}

AccountsPanelWidget::~AccountsPanelWidget() = default;

void AccountsPanelWidget::Setup(ICallBackPasswordPanel* callBack)
{
	m_callBack = callBack;
	SetupView();
}

void AccountsPanelWidget::Hide()
{
	hide();
}

void AccountsPanelWidget::Show()
{
	show();
}

void AccountsPanelWidget::Update()
{
	SetupView();
}

void AccountsPanelWidget::SetupView()
{
	m_model = m_callBack->GetShortDataModel();

	assert(m_model);

	m_ui->shortPasswordDataView->setModel(m_model);
}
