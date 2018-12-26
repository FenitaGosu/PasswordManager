#pragma once

#include <memory>

class QString;

namespace PasswordLogic {

enum class AccountType;

class PreviewAccountInfo
{
public:
	PreviewAccountInfo();
	PreviewAccountInfo(PreviewAccountInfo&& rhs);
	PreviewAccountInfo(const PreviewAccountInfo& rhs);
	PreviewAccountInfo(const QString& id, const QString& name, AccountType type);
	PreviewAccountInfo(const QString& name, AccountType type);
	~PreviewAccountInfo();

	PreviewAccountInfo& operator=(PreviewAccountInfo&& rhs);
	PreviewAccountInfo& operator=(const PreviewAccountInfo& rhs);

	const QString& GetId() const noexcept;
	const QString& GetName() const noexcept;
	AccountType GetType() const noexcept;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
