#include "Enums/AccontType.h"

#include "ModelRoles/ModelAccountTypeRoles.h"

#include "ModelAccountType.h"

using namespace PasswordUI;

namespace {

const std::string& GetText(PasswordLogic::AccountType tool)
{
	static const std::map<PasswordLogic::AccountType, std::string> s_text =
	{
		{ PasswordLogic::AccountType::Simple,	QT_TRANSLATE_NOOP("PasswordUI::ModelAccountType",	"Simple")	},
		{ PasswordLogic::AccountType::Mail,		QT_TRANSLATE_NOOP("PasswordUI::ModelAccountType",	"Mail")		},
		{ PasswordLogic::AccountType::Game,		QT_TRANSLATE_NOOP("PasswordUI::ModelAccountType",	"Game")		},
	};

	const auto it = s_text.find(tool);

	assert(it != s_text.cend());

	return it->second;
}

}

struct ModelAccountType::Impl
{
	Impl(std::vector<PasswordLogic::AccountType>&& tools)
		: tools(std::move(tools))
	{
	}

	std::vector<PasswordLogic::AccountType> tools;
};

ModelAccountType::ModelAccountType(std::vector<PasswordLogic::AccountType>&& tools, QObject *parent)
	: QAbstractListModel(parent)
	, m_impl(std::make_unique<Impl>(std::move(tools)))
{
}

ModelAccountType::~ModelAccountType() = default;

int ModelAccountType::rowCount(const QModelIndex&) const
{
	return static_cast<int>(m_impl->tools.size());
}

QVariant ModelAccountType::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	const size_t r = static_cast<size_t>(index.row());

	switch (static_cast<ModelAccountTypeRoles>(role))
	{
		case ModelAccountTypeRoles::Name:
			return tr(GetText(m_impl->tools[r]).c_str());
		case ModelAccountTypeRoles::Type:
			return static_cast<int>(m_impl->tools[r]);
	}

	return QVariant();
}
