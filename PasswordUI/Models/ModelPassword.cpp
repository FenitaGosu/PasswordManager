#include "ModelRoles/ModelPasswordRoles.h"

#include "ModelPassword.h"

using namespace PasswordUI;

struct ModelPassword::Impl
{
};

ModelPassword::ModelPassword(QObject *parent)
	: QAbstractListModel(parent)
	, m_impl(std::make_unique<Impl>())
{
}

ModelPassword::~ModelPassword() = default;

int ModelPassword::rowCount(const QModelIndex&) const
{
	return 0;
}

QVariant ModelPassword::data(const QModelIndex& index, int role) const
{
	return QVariant();
}
