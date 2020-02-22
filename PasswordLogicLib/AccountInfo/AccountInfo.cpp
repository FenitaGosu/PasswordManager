#include <QString>

#include "PasswordLogicLib/Enums/AccontType.h"

#include "AccountInfo.h"

using namespace PasswordLogic;

struct AccountInfo::Impl
{
	Impl(const QString& id = QString(), const QString& name = QString(), AccountType type = AccountType::Simple)
		: id(id)
		, name(name)
		, type(type)
	{
	}

	QString id;
	QString name;
	AccountType type;
};

AccountInfo::AccountInfo()
	: m_impl(std::make_unique<Impl>())
{
}

AccountInfo::AccountInfo(AccountInfo&& rhs)
	: m_impl(std::move(rhs.m_impl))
{
}

AccountInfo::AccountInfo(const AccountInfo& rhs)
	: m_impl(std::make_unique<Impl>(*rhs.m_impl))
{
}

AccountInfo::AccountInfo(const QString& id, const QString& name, AccountType type)
	: m_impl(std::make_unique<Impl>(id, name, type))
{
}

AccountInfo::AccountInfo(const QString& name, AccountType type)
	: AccountInfo(QString(), name, type)
{
}

AccountInfo& AccountInfo::operator=(AccountInfo&& rhs)
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

const QString& AccountInfo::GetId() const noexcept
{
	return m_impl->id;
}

const QString& AccountInfo::GetName() const noexcept
{
	return  m_impl->name;
}

AccountType AccountInfo::GetType() const noexcept
{
	return  m_impl->type;
}
