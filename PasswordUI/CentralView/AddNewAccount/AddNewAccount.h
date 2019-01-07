#pragma once

#include <QFrame>
#include <QScopedPointer>

namespace Ui {
class AddNewAccount;
}

class QAbstractItemModel;

namespace PasswordUI {

class INewAccountCreator;

class AddNewAccount : public QFrame
{
	Q_OBJECT

public:
	explicit AddNewAccount(QWidget* parent = nullptr);
	~AddNewAccount();

	void Setup(QAbstractItemModel* accountTypeModel, INewAccountCreator* accountCreator);

	void OnAddButtonClicked();

private:
	QScopedPointer<Ui::AddNewAccount> m_ui;

	QAbstractItemModel* m_accountTypeModel;
	INewAccountCreator* m_accountCreator;
};

}
