#pragma once

#include <QFrame>
#include <QScopedPointer>

namespace Ui {
class AddPreviewAccountInfo;
}

namespace PasswordLogic {
enum class AccountType;
}

class QAbstractItemModel;

namespace PasswordUI {

class AddPreviewAccountInfo : public QFrame
{
	Q_OBJECT

public:
	explicit AddPreviewAccountInfo(QWidget* parent = nullptr);
	~AddPreviewAccountInfo();

	QString GetName() const;
	PasswordLogic::AccountType GetType() const;

	void Setup(QAbstractItemModel* accountTypeModel);

signals:
	void typeActivated(PasswordLogic::AccountType type);

private:
	QScopedPointer<Ui::AddPreviewAccountInfo> m_ui;
	QAbstractItemModel* m_model;
};

}
