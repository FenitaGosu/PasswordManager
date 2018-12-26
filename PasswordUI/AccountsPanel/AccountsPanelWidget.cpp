#include <QAbstractItemModel>
#include <QModelIndex>

#include "Event/Event.h"

#include "Enums/Tool.h"

#include "Interfaces/ICallBackPasswordPanel.h"

#include "ModelRoles/ModelAccountRoles.h"

#include "PreviewAccountDelegate.h"

#include "SystemConstants.h"

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

void AccountsPanelWidget::SelectItem(const QString& id)
{
	m_model->setData(QModelIndex(), id, static_cast<int>(ModelAccountRoles::SetSelectedItem));
}

void AccountsPanelWidget::SetupView()
{
	m_model = m_callBack->GetPreviewDataModel();

	assert(m_model);

	m_ui->previewAccountView->setItemDelegate(new PreviewAccountDelegate(this));
	m_ui->previewAccountView->setModel(m_model);

	connect(m_ui->previewAccountView->selectionModel(), &QItemSelectionModel::currentChanged, [callBack = m_callBack](const QModelIndex& index, const QModelIndex&)
	{
		if (index.isValid())
			callBack->HandleEvent(Event(EventType::AccountsPanel, SystemConstants::ACCOUNT_CLICKED, index.data(static_cast<int>(ModelAccountRoles::Id)).toString().toStdString()));
	});

	connect(m_model, &QAbstractListModel::dataChanged, [this](const QModelIndex& index, const QModelIndex&, const QVector<int>& roles)
	{
		if (!roles.empty() && static_cast<ModelAccountRoles>(roles.front()) == ModelAccountRoles::SetSelectedItem)
			OnSelecetItem(index);
	});

	OnSelecetItem(m_model->index(0, 0));
}

void AccountsPanelWidget::OnSelecetItem(const QModelIndex& index)
{
	if (index.isValid())
	{
		m_ui->previewAccountView->selectionModel()->clearSelection();
		m_ui->previewAccountView->selectionModel()->select(index, QItemSelectionModel::Select);
	}
}
