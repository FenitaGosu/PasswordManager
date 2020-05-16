#include "PasswordLogicLib/Enums/AccontType.h"

#include "AccountInfo.h"

using namespace PasswordLogic;

struct AccountInfo::Impl
{
	Impl(const std::string& id = std::string(), const std::string& name = std::string(), AccountType type = AccountType::Simple)
		: id(id)
		, name(name)
		, type(type)
	{
	}

	std::string id;
	std::string name;
	AccountType type;
};

AccountInfo::AccountInfo()
	: m_impl(std::make_unique<Impl>())
{
}

AccountInfo::AccountInfo(AccountInfo&& rhs) noexcept
	: m_impl(std::move(rhs.m_impl))
{
}

AccountInfo::AccountInfo(const AccountInfo& rhs)
	: m_impl(std::make_unique<Impl>(*rhs.m_impl))
{
}

AccountInfo::AccountInfo(const std::string& id, const std::string& name, AccountType type)
	: m_impl(std::make_unique<Impl>(id, name, type))
{
}

AccountInfo::AccountInfo(const std::string& name, AccountType type)
	: AccountInfo(std::string(), name, type)
{
}

AccountInfo& AccountInfo::operator=(AccountInfo&& rhs) noexcept
{
	this->m_impl = std::move(rhs.m_impl);
	return *this;
}

AccountInfo& AccountInfo::operator=(const AccountInfo& rhs)
{
	*(this->m_impl) = *(rhs.m_impl);
	return *this;
}

AccountInfo::~AccountInfo() = default;

const std::string& AccountInfo::GetId() const noexcept
{
	return m_impl->id;
}

const std::string& AccountInfo::GetName() const noexcept
{
	return  m_impl->name;
}

AccountType AccountInfo::GetType() const noexcept
{
	return  m_impl->type;
}
