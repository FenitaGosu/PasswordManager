#include <QString>

#include "Encryption/Interfaces/IKeyProvider.h"
#include "Encryption/XOREncryptor/XOREncryptor.h"

#include "Enums/AccontType.h"
#include "AccountInfo/PreviewAccoutInfo.h"

#include "DataContainer/PreviewAccountsDataContainer.h"

#include "Interfaces/IDataSource.h"

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

std::unique_ptr<PreviewAccountsDataContainer> CreateDataContainer()
{
	return std::make_unique<PreviewAccountsDataContainer>(std::make_unique<Encryption::XOREncryptor>(std::make_unique<KeyProvider>()));
}

}

DataController::DataController(const std::shared_ptr<IDataSource>& dataSource)
	: m_dataSource(dataSource)
{
}

PreviewAccoutsInfo DataController::GetPreviewAccountsInfo()
{
	/*auto container = CreateDataContainer();
	m_dataSource->GetPreviewAccountsInfo(*container.get());

	return container->GetInfo();*/

	/// @todo
	return { {"id1", "test1", AccountType::Simple}, {"id2", "test2", AccountType::Mail}, {"id3", "test3", AccountType::Game}};
}
