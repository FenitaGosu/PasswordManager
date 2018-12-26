#pragma once

#include <memory>

#include "Interfaces/IDataContainer.h"

#include "AccountInfo/AccountInfoDec.h"

namespace Encryption {
class IEncryptor;
}

namespace PasswordLogic {

class EncryptedDataContainer : public IDataContainer
{
public:
	EncryptedDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor);
	~EncryptedDataContainer();

public:
	/// IDataContainer
	void AddDataList(DataList&& data) override;
	const DataList& GetDataList() const override;

	void AddData(Data&& data) override;
	const Data& GetData(size_t i = 0) const override;

protected:
	std::string Encrypt(const std::string& msg) const;
	std::string Decrypt(const std::string& encryptedMsg) const;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
