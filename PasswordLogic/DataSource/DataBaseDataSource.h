#pragma once

#include <memory>

#include "Interfaces/IDataSource.h"

namespace PasswordLogic {

class DataBaseDataSourceImpl;

class DataBaseSource : public IDataSource
{
public:
	DataBaseSource(const std::string& path);
	~DataBaseSource();

	bool IsFisrstStart() const noexcept override;
	std::string GeCurrentMainPassword() const override;
	void SetCurrentMainPassword(const std::string& password) override;

private:
	std::unique_ptr<DataBaseDataSourceImpl> m_dataBase;
};

}
