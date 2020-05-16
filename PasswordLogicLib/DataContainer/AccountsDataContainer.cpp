#include <cassert>

#include "ToolsLib/Same/Same.h"

#include "EncryptionLib/Interfaces/IEncryptor.h"

#include "PasswordLogicLib/AccountInfo/AccountInfo.h"

#include "PasswordLogicLib/Parameters.h"

#include "AccountsDataContainer.h"

using namespace PasswordLogic;

AccountsDataContainer::AccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor, const AccountsInfo& info)
	: EncryptedDataContainer(std::move(encryptor))
{
	DataList dataList;
	dataList.reserve(info.size());

	for (const auto& accountInfo : info)
	{
		Data data;
		data[Parameters::PARAM_ID]		= Encrypt(accountInfo.GetId());
		data[Parameters::PARAM_NAME]	= Encrypt(accountInfo.GetName());
		data[Parameters::PARAM_TYPE]	= Encrypt(std::to_string(static_cast<int>(accountInfo.GetType())));
		dataList.push_back(std::move(data));
	}

	AddDataList(std::move(dataList));
}

AccountsDataContainer::AccountsDataContainer(std::unique_ptr<Encryption::IEncryptor>&& encryptor)
	: EncryptedDataContainer(std::move(encryptor))
{
}

AccountsDataContainer::~AccountsDataContainer() = default;

AccountsInfo AccountsDataContainer::GetAllInfo() const
{
	AccountsInfo info;

	const auto& data = GetDataList();
	info.reserve(static_cast<size_t>(data.size()));

	const auto getValue = [](const Data& data, const std::string& key) -> const std::string&
	{
		const auto it = data.find(key);
		assert(it != data.cend());
		return it->second.Get<const std::string&>();
	};

	for (const auto& d : data)
	{
		const auto id		= Decrypt(getValue(d, Parameters::PARAM_ID));
		const auto name		= Decrypt(getValue(d, Parameters::PARAM_NAME));
		const auto type		= static_cast<AccountType>(std::stoi(Decrypt(getValue(d, Parameters::PARAM_TYPE))));

		info.emplace_back(id, name, type);
	}

	return info;
}
