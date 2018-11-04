#pragma once

#include <QFrame>
#include <QScopedPointer>

#include "Interfaces/IPasswordPanel.h"

namespace Ui {
class PasswordPanelWidget;
}

class QAbstractItemModel;

namespace PasswordUI {

class ICallBackPasswordPanel;

class PasswordPanelWidget : public QFrame, public IPasswordPanel
{
	Q_OBJECT

public:
	explicit PasswordPanelWidget(QWidget* parent = nullptr);
	~PasswordPanelWidget();

	void Setup(ICallBackPasswordPanel *callBack);

	/// IPasswordPanel
	void Hide() override;
	void Show() override;
	void Update() override;

private:
	void SetupView();

private:
	QScopedPointer<Ui::PasswordPanelWidget> m_ui;

	ICallBackPasswordPanel* m_callBack;
	QAbstractItemModel* m_model;

};

}

