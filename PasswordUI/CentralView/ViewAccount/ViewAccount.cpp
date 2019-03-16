#include "ViewAccount.h"

#include "ui_ViewAccount.h"

using namespace PasswordUI;

ViewAccount::ViewAccount(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::ViewAccount())
{
	m_ui->setupUi(this);
}

ViewAccount::~ViewAccount() = default;

void ViewAccount::Setup(QAbstractItemModel* accountTypeModel, ICurrentAccountInfoProvider * infoProvider)
{
	m_accountTypeModel = accountTypeModel;
	m_infoProvider = infoProvider;
}
