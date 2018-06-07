#include "JsonTools/Interfaces/IParserJson.h"
#include "JsonTools/ParserQJson/ParserQJson.h"

#include "ApplicatonSettingsJsonImpl.h"

using namespace PasswordKit;
using namespace JsonTools;

namespace{
const std::string CONFIG_PATH = ":/resources/configs/application.json";
const std::string KEY_ORGANIZATION_NAME = "ORGANIZATION_NAME";
const std::string KEY_APPLICATION_NAME = "APPLICATION_NAME";
}

ApplicatonSettingsJsonImpl::ApplicatonSettingsJsonImpl()
	: m_parser(std::make_unique<ParserQJson>(CONFIG_PATH))
{
}

ApplicatonSettingsJsonImpl::~ApplicatonSettingsJsonImpl() = default;

QString ApplicatonSettingsJsonImpl::GetOrganizationName() const
{
	return QString::fromStdString(m_parser->GetString(KEY_ORGANIZATION_NAME));
}

QString ApplicatonSettingsJsonImpl::GetApplicationName() const
{
	return QString::fromStdString(m_parser->GetString(KEY_APPLICATION_NAME));
}
