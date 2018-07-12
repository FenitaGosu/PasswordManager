#pragma once

#include <memory>
#include <string>

namespace PasswordLogic {

class DataBaseDataSourceImpl
{
public:
	DataBaseDataSourceImpl(const std::string& path);
	~DataBaseDataSourceImpl();

	bool IsNeedSetPassword() const noexcept;
	std::string GeCurrentMainPassword() const;
	void SetCurrentMainPassword(const std::string& password);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
