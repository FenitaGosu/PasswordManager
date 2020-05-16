#pragma once

#include <memory>
#include <string>

namespace PasswordLogic {

enum class AccountType;

class AccountInfo
{
public:
	AccountInfo();
	AccountInfo(AccountInfo&& rhs) noexcept;
	AccountInfo(const AccountInfo& rhs);
	AccountInfo(const std::string& id, const std::string& name, AccountType type);
	AccountInfo(const std::string& name, AccountType type);
	~AccountInfo();

	AccountInfo& operator=(AccountInfo&& rhs) noexcept;
	AccountInfo& operator=(const AccountInfo& rhs);

	const std::string& GetId() const noexcept;
	const std::string& GetName() const noexcept;
	AccountType GetType() const noexcept;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
