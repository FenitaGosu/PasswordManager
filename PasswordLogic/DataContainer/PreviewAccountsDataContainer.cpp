#include <QString>

#include "Tools/Same/Same.h"

#include "Encryption/Interfaces/IEncryptor.h"

#include "AccountInfo/PreviewAccoutInfo.h"

#include "Parameters.h"

#include "PreviewAccountsDataContainer.h"

using namespace PasswordLogic;

struct PreviewAccountsDataContainer::Impl
{
	Impl(std::unique_ptr<Encryption::IEncryptor>&& encryptor)
		: encryptor(std::move(encryptor))
	{
	}

	std::unique_ptr<Encryption::IEncryptor> encryptor;
	DataList data;
};

PreviewAccountsDataContainer::PreviewAccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor, const PreviewAccoutsInfo& info)
	: m_impl(std::make_unique<Impl>(std::move(encryptor)))
{
	DataList dataList;
	dataList.reserve(info.size());

	for (const auto& accountInfo : info)
	{
		Data data;
		data[Parameters::PARAM_ID]		= m_impl->encryptor->Encrypt(accountInfo.GetId().toStdString());
		data[Parameters::PARAM_NAME]	= m_impl->encryptor->Encrypt(accountInfo.GetName().toStdString());
		data[Parameters::PARAM_TYPE]	= m_impl->encryptor->Encrypt(std::to_string(static_cast<int>(accountInfo.GetType())));
		dataList.push_back(std::move(data));
	}

	m_impl->data = std::move(dataList);
}

PreviewAccountsDataContainer::PreviewAccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor)
	: m_impl(std::make_unique<Impl>(std::move(encryptor)))
{
}

PreviewAccountsDataContainer::~PreviewAccountsDataContainer() = default;

PreviewAccoutsInfo PreviewAccountsDataContainer::GetAllInfo() const
{
	PreviewAccoutsInfo info;

	info.reserve(static_cast<size_t>( m_impl->data.size()));

	const auto getValue = [](const Data& data, const std::string& key) -> const std::string&
	{
		const auto it = data.find(key);
		assert(it != data.cend());
		return it->second.Get<const std::string&>();
	};

	for (const auto& data : m_impl->data)
	{
		const auto id		= QString::fromStdString(m_impl->encryptor->Decrypt(getValue(data, Parameters::PARAM_ID)));
		const auto name		= QString::fromStdString(m_impl->encryptor->Decrypt(getValue(data, Parameters::PARAM_NAME)));
		const auto type		= static_cast<AccountType>(std::stoi(m_impl->encryptor->Decrypt(getValue(data, Parameters::PARAM_TYPE))));

		info.emplace_back(id, name, type);
	}

	return info;
}

void PreviewAccountsDataContainer::AddDataList(DataList&& data)
{
	m_impl->data = std::move(data);
}

const DataList& PreviewAccountsDataContainer::GetDataList() const
{
	return m_impl->data;
}

void PreviewAccountsDataContainer::AddData(Data&& data)
{
	m_impl->data.push_back(std::move(data));
}

const Data& PreviewAccountsDataContainer::GetData(size_t i) const
{
	assert(i <= m_impl->data.size());
	return m_impl->data[i];
}
