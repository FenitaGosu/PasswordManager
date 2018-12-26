#include <cassert>

#include "Tools/Same/Same.h"

#include "Encryption/Interfaces/IEncryptor.h"

#include "EncryptedDataContainer.h"

using namespace PasswordLogic;

struct EncryptedDataContainer::Impl
{
	Impl(std::unique_ptr<Encryption::IEncryptor>&& encryptor)
		: encryptor(std::move(encryptor))
	{
	}

	std::unique_ptr<Encryption::IEncryptor> encryptor;
	DataList data;
};

EncryptedDataContainer::EncryptedDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor)
	: m_impl(std::make_unique<Impl>(std::move(encryptor)))
{
}

EncryptedDataContainer::~EncryptedDataContainer() = default;

void EncryptedDataContainer::AddDataList(DataList&& data)
{
	m_impl->data = std::move(data);
}

const DataList& EncryptedDataContainer::GetDataList() const
{
	return m_impl->data;
}

void EncryptedDataContainer::AddData(Data&& data)
{
	m_impl->data.push_back(std::move(data));
}

const Data& EncryptedDataContainer::GetData(size_t i) const
{
	assert(i <= m_impl->data.size());
	return m_impl->data[i];
}

std::string EncryptedDataContainer::Encrypt(const std::string& msg) const
{
	return m_impl->encryptor->Encrypt(msg);
}

std::string EncryptedDataContainer::Decrypt(const std::string& encryptedMsg) const
{
	return m_impl->encryptor->Decrypt(encryptedMsg);
}
