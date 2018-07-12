#pragma once

#include <memory>

#include "Interfaces/IDataSource.h"
#include "Interfaces/ICredentialSource.h"

namespace PasswordLogic {

class DataBaseDataSourceImpl;

class DataBaseDataSource
	: public IDataSource
	, public ICredentialSource
{
public:
	DataBaseDataSource(const std::string& path);
	~DataBaseDataSource();

	bool IsNeedSetPassword() const noexcept override;
	std::string GeCurrentMainPassword() const override;
	void SetCurrentMainPassword(const std::string& password) override;

private:
	std::unique_ptr<DataBaseDataSourceImpl> m_dataBase;
};

}
