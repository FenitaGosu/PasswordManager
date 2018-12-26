#pragma once

#include <QFrame>
#include <QScopedPointer>

#include "Interfaces/IAccountsPanel.h"

namespace Ui {
class AccountsPanelWidget;
}

class QAbstractItemModel;

namespace PasswordUI {

class ICallBackPasswordPanel;

class AccountsPanelWidget : public QFrame, public IAccountsPanel
{
	Q_OBJECT

public:
	explicit AccountsPanelWidget(QWidget* parent = nullptr);
	~AccountsPanelWidget();

	void Setup(ICallBackPasswordPanel *callBack);

	/// IAccountsPanel
	void Hide() override;
	void Show() override;
	void Update() override;
	void SelectItem(const QString& id) override;

private:
	void SetupView();

private slots:
	void OnSelecetItem(const QModelIndex& index);

private:
	QScopedPointer<Ui::AccountsPanelWidget> m_ui;

	ICallBackPasswordPanel* m_callBack;
	QAbstractItemModel* m_model;

};

}

