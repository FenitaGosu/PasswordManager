#pragma once

#include <memory.h>

#include <QAbstractListModel>

#include "PasswordLogic/AccountInfo/AccountInfoDec.h"

namespace PasswordUI {

class ModelAccount : public QAbstractListModel
{
public:
	ModelAccount(PasswordLogic::PreviewAccoutsInfo&& data, QObject *parent = nullptr);
	~ModelAccount();

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
