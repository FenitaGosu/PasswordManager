#pragma once

#include <memory>

class QString;

namespace PasswordLogic {

enum class AccountType;

class AccountInfo
{
public:
	AccountInfo();
	AccountInfo(AccountInfo&& rhs);
	AccountInfo(const AccountInfo& rhs);
	AccountInfo(const QString& id, const QString& name, AccountType type);
	AccountInfo(const QString& name, AccountType type);
	~AccountInfo();

	AccountInfo& operator=(AccountInfo&& rhs);
	AccountInfo& operator=(const AccountInfo& rhs);

	const QString& GetId() const noexcept;
	const QString& GetName() const noexcept;
	AccountType GetType() const noexcept;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
