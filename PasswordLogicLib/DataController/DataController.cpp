#include "EncryptionLib/Interfaces/IKeyProvider.h"
#include "EncryptionLib/XOREncryptor/XOREncryptor.h"

#include "PasswordLogicLib/Enums/AccontType.h"
#include "PasswordLogicLib/AccountInfo/AccountInfo.h"

#include "PasswordLogicLib/DataContainer/AccountsDataContainer.h"

#include "PasswordLogicLib/Interfaces/IDataSource.h"

#include "DataController.h"

using namespace PasswordLogic;

namespace {

class KeyProvider : public Encryption::IKeyProvider
{
public:
	std::string GetStringKey() const
	{
		return std::to_string(56 * 4) + std::string("6d6bc421") + std::string("feb2412b51e2") + std::to_string(10 / 5);
	}
};

std::unique_ptr<AccountsDataContainer> CreateDataContainer()
{
	return std::make_unique<AccountsDataContainer>(std::make_unique<Encryption::XOREncryptor>(std::make_unique<KeyProvider>()));
}

std::unique_ptr<AccountsDataContainer> CreateDataContainer(const AccountsInfo& info)
{
	return std::make_unique<AccountsDataContainer>(std::make_unique<Encryption::XOREncryptor>(std::make_unique<KeyProvider>()), info);
}

}

DataController::DataController(const std::shared_ptr<IDataSource>& dataSource)
	: m_dataSource(dataSource)
{
}

AccountsInfo DataController::GetAccountsInfo() const
{
	const auto container = CreateDataContainer();
	m_dataSource->GetAccountsInfo(*container.get());

	return container->GetAllInfo();
}

void DataController::AddNewAccount(const AccountInfo& info)
{
	auto container = CreateDataContainer({ info });

	m_dataSource->AddNewAccount(*container.get());
}
