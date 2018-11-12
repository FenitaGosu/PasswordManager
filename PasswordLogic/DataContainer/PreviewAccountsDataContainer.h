#pragma once

#include <memory>

#include "Interfaces/IDataContainer.h"

#include "AccountInfo/AccountInfoDec.h"


namespace Encryption {
class IEncryptor;
}

namespace PasswordLogic {

class PreviewAccountsDataContainer : public IDataContainer
{
public:
	PreviewAccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor, const PreviewAccoutsInfo& info);
	PreviewAccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor);
	~PreviewAccountsDataContainer();

	PreviewAccoutsInfo GetInfo();

/// IDataContainer
	void AddData(QVariant&& data) override;
	QVariant GetData() override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
