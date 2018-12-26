#include <QAbstractItemView>
#include <QUuid>

#include "PasswordLogic/AccountInfo/PreviewAccountInfo.h"
#include "PasswordLogic/AccountInfo/AccountInfo.h"

#include "Interfaces/INewAccountCreator.h"

#include "AddNewAccount.h"

#include "ui_AddNewAccount.h"

using namespace PasswordUI;

AddNewAccount::AddNewAccount(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::AddNewAccount())
{
	m_ui->setupUi(this);
}

AddNewAccount::~AddNewAccount() = default;

void AddNewAccount::Setup(QAbstractItemModel* accountTypeModel, INewAccountCreator* accountCreator)
{
	connect(m_ui->addPreviewAccountInfoWidget, &AddPreviewAccountInfo::typeActivated, m_ui->addMainInfoWidget, &AddMainAccountInfo::OnTypeActivated);

	m_accountTypeModel = accountTypeModel;
	m_accountCreator = accountCreator;

	m_ui->addPreviewAccountInfoWidget->Setup(m_accountTypeModel);

	connect(m_ui->addButton, &QAbstractButton::clicked, this, &AddNewAccount::OnAddButtonClicked);
}

void AddNewAccount::OnAddButtonClicked()
{
	m_accountCreator->CreateNewAccount(PasswordLogic::PreviewAccountInfo(QUuid::createUuid().toString(), m_ui->addPreviewAccountInfoWidget->GetName(), m_ui->addPreviewAccountInfoWidget->GetType()),
									   PasswordLogic::AccountInfo());
}
