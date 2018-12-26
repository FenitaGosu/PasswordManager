#pragma once

#include <QFrame>
#include <QScopedPointer>

#include "Interfaces/ICentralView.h"

namespace Ui {
class CentralView;
}

namespace PasswordUI {

class ICallBackCentralView;
class INewAccountCreator;

class CentralView : public QFrame, public ICentralView
{
	Q_OBJECT

public:
	explicit CentralView(QWidget* parent = nullptr);
	~CentralView();

	void Setup(ICallBackCentralView* callBack, INewAccountCreator* accountCreator);

	/// ICentralView
	void ActivateMode(Mode mode) override;

private:
	QScopedPointer<Ui::CentralView> m_ui;
};

}
