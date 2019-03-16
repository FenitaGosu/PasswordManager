#pragma once

#include <QFrame>
#include <QScopedPointer>

namespace Ui {
class ViewPreviewAccountInfo;
}

namespace PasswordUI {

class ViewPreviewAccountInfo : public QFrame
{
	Q_OBJECT

public:
	explicit ViewPreviewAccountInfo(QWidget* parent = nullptr);
	~ViewPreviewAccountInfo();

private:
	QScopedPointer<Ui::ViewPreviewAccountInfo> m_ui;
};

}
