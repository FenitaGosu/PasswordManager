#include <QAbstractItemView>

#include "PasswordLogic/Enums/AccontType.h"

#include "ModelRoles/ModelAccountTypeRoles.h"

#include "AddPreviewAccountInfo.h"

#include "ui_AddPreviewAccountInfo.h"

using namespace PasswordUI;

AddPreviewAccountInfo::AddPreviewAccountInfo(QWidget* parent)
	: QFrame(parent)
	, m_ui(new Ui::AddPreviewAccountInfo())
{
	m_ui->setupUi(this);
}

QString AddPreviewAccountInfo::GetName() const
{
	return m_ui->nameLineEdit->text();
}

PasswordLogic::AccountType AddPreviewAccountInfo::GetType() const
{
	return static_cast<PasswordLogic::AccountType>(m_ui->typeComboBox->currentData().toInt());
}

AddPreviewAccountInfo::~AddPreviewAccountInfo() = default;

void AddPreviewAccountInfo::Setup(QAbstractItemModel* accountTypeModel)
{
	m_model = accountTypeModel;

	for (int i = 0, sz = m_model->rowCount(); i < sz; ++i)
	{
		const auto index = m_model->index(i, 0);
		const auto type = m_model->data(index, static_cast<int>(ModelAccountTypeRoles::Type)).toInt();
		const auto name = m_model->data(index, static_cast<int>(ModelAccountTypeRoles::Name)).toString();

		m_ui->typeComboBox->addItem(name, type);
	}

	connect(m_ui->typeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int index)
	{
		emit typeActivated(static_cast<PasswordLogic::AccountType>(m_ui->typeComboBox->itemData(index).toInt()));
	});

	emit typeActivated(static_cast<PasswordLogic::AccountType>(m_ui->typeComboBox->currentData().toInt()));
}
