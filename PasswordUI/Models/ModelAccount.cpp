#include "PasswordLogic/AccountInfo/PreviewAccountInfo.h"

#include "ModelRoles/ModelAccountRoles.h"

#include "ModelAccount.h"

using namespace PasswordUI;

struct ModelAccount::Impl
{
	Impl(PasswordLogic::PreviewAccountsInfo&& data)
		: data(std::move(data))
	{
	}

	PasswordLogic::PreviewAccountsInfo data;
};

ModelAccount::ModelAccount(PasswordLogic::PreviewAccountsInfo&& data, QObject *parent)
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
		default:
			break;
	}

	return QVariant();
}

bool ModelAccount::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (!index.isValid())
	{
		switch (static_cast<ModelAccountRoles>(role))
		{
			case ModelAccountRoles::SetSelectedItem:
			{
				const auto it = std::find_if(m_impl->data.cbegin(), m_impl->data.cend(), [id = value.toString()](const auto& item){ return item.GetId() == id; });

				if (it == m_impl->data.cend())
					return false;

				const auto selectIndex = this->index(static_cast<int>(std::distance(m_impl->data.cbegin(), it)), 0);

				emit dataChanged(selectIndex, selectIndex, { static_cast<int>(ModelAccountRoles::SetSelectedItem) });

				return true;
			}

			default:
				break;
		}
	}
	else
	{
	}

	return false;
}
