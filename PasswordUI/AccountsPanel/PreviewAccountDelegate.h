#pragma once

#include <QStyledItemDelegate>

namespace PasswordUI {

class PreviewAccountDelegate : public QStyledItemDelegate
{
public:
	PreviewAccountDelegate(QObject* parent = nullptr);

	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

}
