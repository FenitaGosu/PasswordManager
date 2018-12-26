#pragma once

#include <QFrame>
#include <QScopedPointer>

namespace Ui {
class AddMainAccountInfo;
}

namespace PasswordLogic {
enum class AccountType;
}

namespace PasswordUI {

class AddMainAccountInfo : public QFrame
{
	Q_OBJECT

public:
	explicit AddMainAccountInfo(QWidget* parent = nullptr);
	~AddMainAccountInfo();

public slots:
	void OnTypeActivated(PasswordLogic::AccountType type);

private:
	QScopedPointer<Ui::AddMainAccountInfo> m_ui;
};

}
