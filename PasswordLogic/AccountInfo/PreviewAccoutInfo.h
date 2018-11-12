#pragma once

#include <memory>

class QString;

namespace PasswordLogic {

enum class AccountType;

class PreviewAccoutInfo
{
public:
	PreviewAccoutInfo();
	PreviewAccoutInfo(PreviewAccoutInfo&& rhs);
	PreviewAccoutInfo(const PreviewAccoutInfo& rhs);
	PreviewAccoutInfo(const QString& id, const QString& name, AccountType type);
	~PreviewAccoutInfo();

	PreviewAccoutInfo& operator=(PreviewAccoutInfo&& rhs);
	PreviewAccoutInfo& operator=(const PreviewAccoutInfo& rhs);

	const QString& GetId() const noexcept;
	const QString& GetName() const noexcept;
	AccountType GetType() const noexcept;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
