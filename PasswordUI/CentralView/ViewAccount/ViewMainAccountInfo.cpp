#include "ViewMainAccountInfo.h"

#include "ui_ViewMainAccountInfo.h"

using namespace PasswordUI;

ViewMainAccountInfo::ViewMainAccountInfo(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::ViewMainAccountInfo())
{
	m_ui->setupUi(this);
}

ViewMainAccountInfo::~ViewMainAccountInfo() = default;

void ViewMainAccountInfo::Setup(QAbstractItemModel* accountTypeModel)
{
	m_accountTypeModel = accountTypeModel;
}
