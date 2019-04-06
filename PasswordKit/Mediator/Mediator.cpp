#include <QCoreApplication>

#include "Interfaces/IApplicationSettings.h"

#include "Mediator.h"

using namespace PasswordKit;

struct Mediator::Impl
{
	Impl(int argc, char* argv[])
		: app(argc, argv)
	{
	}

	QCoreApplication app;
};

Mediator::Mediator(int argc, char* argv[])
	: m_impl(std::make_unique<Impl>(argc, argv))
{
}

PasswordKit::Mediator::~Mediator() = default;

std::unique_ptr<IApplicationSettings> PasswordKit::Mediator::GetApplicationSettings() const
{
	return std::unique_ptr<IApplicationSettings>();
}
