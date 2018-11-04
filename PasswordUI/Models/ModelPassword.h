#pragma once

#include <memory.h>

#include <QAbstractListModel>

namespace PasswordUI {

class ModelPassword : public QAbstractListModel
{
public:
	ModelPassword(QObject *parent = nullptr);
	~ModelPassword();

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
