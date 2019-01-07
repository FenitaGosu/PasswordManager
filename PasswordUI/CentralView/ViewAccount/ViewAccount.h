#pragma once

#include <QFrame>
#include <QScopedPointer>

namespace Ui {
class ViewAccount;
}

class QAbstractItemModel;

namespace PasswordUI {

class ICurrentAccountInfoProvider;

class ViewAccount : public QFrame
{
	Q_OBJECT

public:
	explicit ViewAccount(QWidget* parent = nullptr);
	~ViewAccount();

	void Setup(QAbstractItemModel* accountTypeModel, ICurrentAccountInfoProvider* infoProvider);

private:
	QScopedPointer<Ui::ViewAccount> m_ui;

	QAbstractItemModel* m_accountTypeModel;
	ICurrentAccountInfoProvider* m_infoProvider;
};

}
