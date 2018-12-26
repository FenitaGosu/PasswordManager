#include <cassert>

#include "Interfaces/ICallBackCentralView.h"
#include "Interfaces/INewAccountCreator.h"

#include "CentralView.h"

#include "ui_CentralView.h"

using namespace PasswordUI;

CentralView::CentralView(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::CentralView())
{
	m_ui->setupUi(this);
}

CentralView::~CentralView() = default;

void CentralView::Setup(ICallBackCentralView *callBack, INewAccountCreator* accountCreator)
{
	m_ui->addNewAccountWidget->Setup(callBack->GetAccountTypeModel(), accountCreator);
}

void CentralView::ActivateMode(ICentralView::Mode mode)
{
	const static std::map<ICentralView::Mode, QWidget*> s_widgets =
	{
		{ ICentralView::Mode::AddNewAccount,	m_ui->addNewAccountWidget },
		{ ICentralView::Mode::ViewAccount,		m_ui->viewAccountWidget },
	};

	const auto it = s_widgets.find(mode);

	assert(it != s_widgets.cend());

	m_ui->stackedWidget->setCurrentWidget(it->second);
}
