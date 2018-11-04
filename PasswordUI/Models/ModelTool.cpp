#include "Enums/Tool.h"

#include "ModelRoles/ModelToolRoles.h"

#include "ModelTool.h"

using namespace PasswordUI;

namespace {

const std::string& GetText(Tool tool)
{
	static const std::map<Tool, std::string> s_text =
	{
		{ Tool::Passwords,		QT_TRANSLATE_NOOP("PasswordUI::ModelTool",	"All passwords")	},
		{ Tool::AddPassword,	QT_TRANSLATE_NOOP("PasswordUI::ModelTool",	"Add password")		},
		{ Tool::DeletePassword,	QT_TRANSLATE_NOOP("PasswordUI::ModelTool",	"Delete password")	},
	};

	const auto it = s_text.find(tool);

	assert(it != s_text.cend());

	return it->second;
}

}


struct ModelTool::Impl
{
	Impl(std::vector<Tool>&& tools)
		: tools(std::move(tools))
	{
	}

	std::vector<Tool> tools;
};

ModelTool::ModelTool(std::vector<Tool>&& tools, QObject *parent)
	: QAbstractListModel(parent)
	, m_impl(std::make_unique<Impl>(std::move(tools)))
{
}

ModelTool::~ModelTool() = default;

int ModelTool::rowCount(const QModelIndex&) const
{
	return static_cast<int>(m_impl->tools.size());
}

QVariant ModelTool::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	const size_t r = static_cast<size_t>(index.row());

	switch (static_cast<ModelToolRoles>(role))
	{
		case ModelToolRoles::Name:
			return tr(GetText(m_impl->tools[r]).c_str());
		case ModelToolRoles::Type:
			return static_cast<int>(m_impl->tools[r]);
	}

	return QVariant();
}
