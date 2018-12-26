#include "PasswordLogic/Enums/AccontType.h"

#include "AddMainAccountInfo.h"

#include "ui_AddMainAccountInfo.h"

using namespace PasswordUI;

AddMainAccountInfo::AddMainAccountInfo(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::AddMainAccountInfo())
{
	m_ui->setupUi(this);
}

AddMainAccountInfo::~AddMainAccountInfo() = default;

void AddMainAccountInfo::OnTypeActivated(PasswordLogic::AccountType type)
{
}

