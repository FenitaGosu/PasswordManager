#include <QPainter>
#include <QStyleOptionViewItem>

#include "ModelRoles/ModelAccountRoles.h"

#include "PreviewAccountDelegate.h"

using namespace PasswordUI;

namespace  {
void DrawItem(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index)
{
	painter->save();
	painter->drawText(option.rect, index.data(static_cast<int>(ModelAccountRoles::Name)).toString());
	painter->restore();
}

}

PreviewAccountDelegate::PreviewAccountDelegate(QObject* parent)
	: QStyledItemDelegate(parent)
{
}

void PreviewAccountDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QStyledItemDelegate::paint(painter, option, index);
	DrawItem(painter, option, index);
}
