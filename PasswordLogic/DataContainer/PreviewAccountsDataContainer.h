#pragma once

#include <memory>

#include "AccountInfo/AccountInfoDec.h"

#include "EncryptedDataContainer.h"

namespace Encryption {
class IEncryptor;
}

namespace PasswordLogic {

class PreviewAccountsDataContainer : public EncryptedDataContainer
{
public:
	PreviewAccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor, const PreviewAccountsInfo& info);
	PreviewAccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor);
	~PreviewAccountsDataContainer();

	PreviewAccountsInfo GetAllInfo() const;
};

}
