#include <QString>

#include "Enums/AccontType.h"

#include "PreviewAccountInfo.h"

using namespace PasswordLogic;

struct PreviewAccountInfo::Impl
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

PreviewAccountInfo::PreviewAccountInfo()
	: m_impl(std::make_unique<Impl>())
{
}

PreviewAccountInfo::PreviewAccountInfo(PreviewAccountInfo&& rhs)
	: m_impl(std::move(rhs.m_impl))
{
}

PreviewAccountInfo::PreviewAccountInfo(const PreviewAccountInfo& rhs)
	: m_impl(std::make_unique<Impl>(*rhs.m_impl))
{
}

PreviewAccountInfo::PreviewAccountInfo(const QString& id, const QString& name, AccountType type)
	: m_impl(std::make_unique<Impl>(id, name, type))
{
}

PreviewAccountInfo::PreviewAccountInfo(const QString& name, AccountType type)
	: PreviewAccountInfo(QString(), name, type)
{
}

PreviewAccountInfo& PreviewAccountInfo::operator=(PreviewAccountInfo&& rhs)
{
	this->m_impl = std::move(rhs.m_impl);
	return *this;
}

PreviewAccountInfo& PreviewAccountInfo::operator=(const PreviewAccountInfo& rhs)
{
	*(this->m_impl) = *(rhs.m_impl);
	return *this;
}

PreviewAccountInfo::~PreviewAccountInfo() = default;

const QString& PreviewAccountInfo::GetId() const noexcept
{
	return m_impl->id;
}

const QString& PreviewAccountInfo::GetName() const noexcept
{
	return  m_impl->name;
}

AccountType PreviewAccountInfo::GetType() const noexcept
{
	return  m_impl->type;
}
