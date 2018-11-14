#pragma once

#include <memory>

#include "AccountInfo/AccountInfoDec.h"

namespace PasswordLogic {

class IDataSource;

class DataController
{
public:
	DataController(const std::shared_ptr<IDataSource>& dataSource);

	PreviewAccoutsInfo GetPreviewAccountsInfo() const;
	void AddPreviewAccountInfo(const PreviewAccoutInfo& info);
	void AddPreviewAccountsInfo(const PreviewAccoutsInfo& info);

private:
	std::shared_ptr<IDataSource> m_dataSource;
};

}
