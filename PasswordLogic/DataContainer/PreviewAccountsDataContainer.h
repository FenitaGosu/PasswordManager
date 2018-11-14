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

	PreviewAccoutsInfo GetAllInfo() const;

/// IDataContainer
	void AddDataList(DataList&& data) override;
	const DataList& GetDataList() const override;

	void AddData(Data&& data) override;
	const Data& GetData(size_t i = 0) const override;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
