#pragma once

#include <memory.h>

#include <QAbstractListModel>

namespace PasswordLogic {
	enum class AccountType;
}

namespace PasswordUI {

class ModelAccountType : public QAbstractListModel
{
public:
	ModelAccountType(std::vector<PasswordLogic::AccountType>&& tools, QObject *parent = nullptr);
	~ModelAccountType();

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
