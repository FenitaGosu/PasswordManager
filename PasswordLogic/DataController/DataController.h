#pragma once

#include <memory>

#include "AccountInfo/AccountInfoDec.h"

namespace PasswordLogic {

class IDataSource;

class DataController
{
public:
	DataController(const std::shared_ptr<IDataSource>& dataSource);

	PreviewAccountsInfo GetPreviewAccountsInfo() const;
	void AddNewAccount(const PreviewAccountInfo& previewInfo, const AccountInfo& mainInfo);

private:
	std::shared_ptr<IDataSource> m_dataSource;
};

}
