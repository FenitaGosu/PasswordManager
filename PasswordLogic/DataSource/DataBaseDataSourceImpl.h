#pragma once

#include <memory>
#include <string>

#include "SameContainers.h"

namespace PasswordLogic {

class IDataContainer;

class DataBaseDataSourceImpl
{
public:
	DataBaseDataSourceImpl(const std::string& path);
	~DataBaseDataSourceImpl();

	bool IsNeedSetPassword() const noexcept;
	std::string GeCurrentMainPassword() const;
	void SetCurrentMainPassword(const std::string& password);

	DataList GetPreviewAccountsInfo() const;
	void AddNewAccount(const DataList& previewData, const DataList& accountData);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
