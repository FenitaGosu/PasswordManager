#include <QVariant>

#include "Encryption/Interfaces/IEncryptor.h"

#include "AccountInfo/PreviewAccoutInfo.h"

#include "PreviewAccountsDataContainer.h"

using namespace PasswordLogic;

namespace {
const PreviewAccoutsInfo G_EMTY_INFO;
}

struct PreviewAccountsDataContainer::Impl
{
	Impl(std::unique_ptr<Encryption::IEncryptor>&& encryptor, const PreviewAccoutsInfo& info)
		: encryptor(std::move(encryptor))
		, info(info)
	{
	}

	std::unique_ptr<Encryption::IEncryptor> encryptor;
	const PreviewAccoutsInfo& info;
	QVariant data;
};

PreviewAccountsDataContainer::PreviewAccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor, const PreviewAccoutsInfo& info)
	: m_impl(std::make_unique<Impl>(std::move(encryptor), info))
{
}

PreviewAccountsDataContainer::PreviewAccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor)
	: PreviewAccountsDataContainer(std::move(encryptor), G_EMTY_INFO)
{
}

PreviewAccountsDataContainer::~PreviewAccountsDataContainer() = default;

void PreviewAccountsDataContainer::AddData(QVariant&& data)
{
	m_impl->data = std::move(data);
}

QVariant PreviewAccountsDataContainer::GetData()
{
	/// @todo m_impl->info to QVariant, use m_impl->encryptor
	return QVariant();
}

PreviewAccoutsInfo PreviewAccountsDataContainer::GetInfo()
{
	/// @todo m_impl->data to IPreviewAccoutsInfo, use m_impl->encryptor
	return G_EMTY_INFO;
}
