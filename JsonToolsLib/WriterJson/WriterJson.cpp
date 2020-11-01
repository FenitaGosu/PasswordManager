#include <stdexcept>
#include <sstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "ToolsLib/StringFormat/StringFormat.h"

#include "WriterJson.h"

namespace {
	const std::string MAIN_TAG = "MAIN";
}

using namespace JsonTools;

struct WriterJson::Impl
{
	void AlredyExist(const std::string& key)
	{
		if (m_rootPt.find(key) != m_rootPt.not_found())
			throw std::logic_error(Tools::StringFormat::Format("Key %s alredy contains in json.", key.c_str()));
	}

	boost::property_tree::ptree m_rootPt;
};

WriterJson::WriterJson()
	: m_impl(std::make_unique<Impl>())
{
}

WriterJson::~WriterJson() = default;

void WriterJson::AddBool(const std::string& key, bool value)
{
	m_impl->AlredyExist(key);
	m_impl->m_rootPt.add(key, value);
}

void WriterJson::AddDouble(const std::string& key, double value)
{
	m_impl->AlredyExist(key);
	m_impl->m_rootPt.add(key, value);
}

void WriterJson::AddInt(const std::string& key, int value)
{
	m_impl->AlredyExist(key);
	m_impl->m_rootPt.add(key, value);
}

void WriterJson::AddString(const std::string& key, const std::string& value)
{
	m_impl->AlredyExist(key);
	m_impl->m_rootPt.add(key, value);
}

void WriterJson::AddObject(const std::string& key, const std::shared_ptr<IWriterJson>& object)
{
	m_impl->AlredyExist(key);

	const auto writerJsonObjet = std::dynamic_pointer_cast<WriterJson>(object);

	if (!writerJsonObjet)
		throw std::runtime_error("Object is not WriterJson.");

	m_impl->m_rootPt.add_child(key, writerJsonObjet->m_impl->m_rootPt);
}

std::string WriterJson::Serialize() const
{
	boost::property_tree::ptree mainPt;

	mainPt.add_child(MAIN_TAG, m_impl->m_rootPt);

	std::ostringstream ss;
	boost::property_tree::write_json(ss, mainPt, false);

	return ss.str();
}
