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

std::unique_ptr<PreviewAccountsDataContainer> CreateDataContainer(const PreviewAccoutsInfo& info)
{
	return std::make_unique<PreviewAccountsDataContainer>(std::make_unique<Encryption::XOREncryptor>(std::make_unique<KeyProvider>()), info);
}

}

DataController::DataController(const std::shared_ptr<IDataSource>& dataSource)
	: m_dataSource(dataSource)
{
}

void DataController::AddPreviewAccountInfo(const PreviewAccoutInfo& info)
{
	AddPreviewAccountsInfo({ info });
}

void DataController::AddPreviewAccountsInfo(const PreviewAccoutsInfo& info)
{
	auto container = CreateDataContainer(info);
	m_dataSource->AddPreviewAccountsInfo(*container.get());
}

PreviewAccoutsInfo DataController::GetPreviewAccountsInfo() const
{
	const auto container = CreateDataContainer();
	m_dataSource->GetPreviewAccountsInfo(*container.get());

	return container->GetAllInfo();
}
