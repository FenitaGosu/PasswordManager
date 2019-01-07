#pragma once

#include <QFrame>
#include <QScopedPointer>

namespace Ui {
class ViewMainAccountInfo;
}

class QAbstractItemModel;

namespace PasswordUI {

class ViewMainAccountInfo : public QFrame
{
	Q_OBJECT

public:
	explicit ViewMainAccountInfo(QWidget* parent = nullptr);
	~ViewMainAccountInfo();

	void Setup(QAbstractItemModel* accountTypeModel);

private:
	QScopedPointer<Ui::ViewMainAccountInfo> m_ui;

	QAbstractItemModel* m_accountTypeModel;
};

}
