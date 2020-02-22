#pragma once

#include <memory>

#include "PasswordLogicLib/AccountInfo/AccountInfoDec.h"

#include "EncryptedDataContainer.h"

namespace Encryption {
class IEncryptor;
}

namespace PasswordLogic {

class AccountsDataContainer : public EncryptedDataContainer
{
public:
	AccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor, const AccountsInfo& info);
	AccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor);
	~AccountsDataContainer();

	AccountsInfo GetAllInfo() const;
};

}
