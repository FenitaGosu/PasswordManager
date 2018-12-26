#include "Encryption/Interfaces/IEncryptor.h"

#include "AccountsDataContainer.h"

using namespace PasswordLogic;

AccountsDataContainer::AccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor)
	: EncryptedDataContainer(std::move(encryptor))
{
}

AccountsDataContainer::AccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor, const AccountsInfo& info)
	: EncryptedDataContainer(std::move(encryptor))
{
}

AccountsDataContainer::~AccountsDataContainer() = default;
