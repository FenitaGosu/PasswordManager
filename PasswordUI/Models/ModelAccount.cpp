#include "PasswordLogic/AccountInfo/PreviewAccoutInfo.h"

#include "ModelRoles/ModelAccountRoles.h"

#include "ModelAccount.h"

using namespace PasswordUI;

struct ModelAccount::Impl
{
	Impl(PasswordLogic::PreviewAccoutsInfo&& data)
		: data(std::move(data))
	{
	}

	PasswordLogic::PreviewAccoutsInfo data;
};

ModelAccount::ModelAccount(PasswordLogic::PreviewAccoutsInfo&& data, QObject *parent)
	: QAbstractListModel(parent)
	, m_impl(std::make_unique<Impl>(std::move(data)))
{
}

ModelAccount::~ModelAccount() = default;

int ModelAccount::rowCount(const QModelIndex&) const
{
	return static_cast<int>(m_impl->data.size());
}

QVariant ModelAccount::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	const size_t r = static_cast<size_t>(index.row());

	switch (static_cast<ModelAccountRoles>(role))
	{
		case ModelAccountRoles::Id:
			return m_impl->data[r].GetId();
		case ModelAccountRoles::Name:
			return m_impl->data[r].GetName();
		case ModelAccountRoles::Type:
			return static_cast<int>(m_impl->data[r].GetType());
	}

	return QVariant();
}
