#pragma once

#include <memory.h>

#include <QAbstractListModel>

namespace PasswordUI {

enum class Tool;

class ModelTool : public QAbstractListModel
{
public:
	ModelTool(std::vector<Tool>&& tools, QObject *parent = nullptr);
	~ModelTool();

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
