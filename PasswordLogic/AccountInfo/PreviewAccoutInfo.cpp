#include <QString>

#include "Enums/AccontType.h"

#include "PreviewAccoutInfo.h"

using namespace PasswordLogic;

struct PreviewAccoutInfo::Impl
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

PreviewAccoutInfo::PreviewAccoutInfo()
	: m_impl(std::make_unique<Impl>())
{
}

PreviewAccoutInfo::PreviewAccoutInfo(PreviewAccoutInfo&& rhs)
	: m_impl(std::move(rhs.m_impl))
{
}

PreviewAccoutInfo::PreviewAccoutInfo(const PreviewAccoutInfo& rhs)
	: m_impl(std::make_unique<Impl>(*rhs.m_impl))
{
}

PreviewAccoutInfo::PreviewAccoutInfo(const QString& id, const QString& name, AccountType type)
	: m_impl(std::make_unique<Impl>(id, name, type))
{
}

PreviewAccoutInfo& PreviewAccoutInfo::operator=(PreviewAccoutInfo&& rhs)
{
	this->m_impl = std::move(rhs.m_impl);
	return *this;
}

PreviewAccoutInfo& PreviewAccoutInfo::operator=(const PreviewAccoutInfo& rhs)
{
	*(this->m_impl) = *(rhs.m_impl);
	return *this;
}

PreviewAccoutInfo::~PreviewAccoutInfo() = default;

const QString& PreviewAccoutInfo::GetId() const noexcept
{
	return m_impl->id;
}

const QString& PreviewAccoutInfo::GetName() const noexcept
{
	return  m_impl->name;
}

AccountType PreviewAccoutInfo::GetType() const noexcept
{
	return  m_impl->type;
}
