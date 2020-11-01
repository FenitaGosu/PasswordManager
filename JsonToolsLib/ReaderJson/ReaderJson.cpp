#include <cassert>
#include <stdexcept>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "ReaderJson.h"

using namespace JsonTools;

namespace {
const std::string MAIN_TAG = "MAIN";
}

struct ReaderJson::Impl
{
	boost::property_tree::ptree m_pt;
};

ReaderJson::ReaderJson(const std::string& jsonStr)
	: m_impl(std::make_unique<Impl>())
{
	try
	{
		if (jsonStr.empty())
			throw std::logic_error("Json file is empty.");

		std::stringstream ss;
		ss << jsonStr;

		boost::property_tree::ptree pt;
		boost::property_tree::read_json(ss, pt);

		const auto optional = pt.get_child_optional(MAIN_TAG);

		if (!optional.has_value())
			throw std::logic_error("Not contains main section \"MAIN\".");

		m_impl->m_pt = optional.get();
	}
	catch (boost::property_tree::json_parser_error& error)
	{
		throw std::logic_error("Invalid json file.");
	}
	catch (std::logic_error& error)
	{
		throw;
	}
}

ReaderJson::~ReaderJson() = default;

bool ReaderJson::GetBool(const std::string& key, const bool defaultValue) const
{
	return m_impl->m_pt.get(key, defaultValue);
}

double ReaderJson::GetDouble(const std::string& key, const double defaultValue) const
{
	return m_impl->m_pt.get(key, defaultValue);
}

int ReaderJson::GetInt(const std::string& key, const int defaultValue) const
{
	return m_impl->m_pt.get(key, defaultValue);
}

std::string ReaderJson::GetString(const std::string& key, const std::string& defaultValue) const
{
	return m_impl->m_pt.get(key, defaultValue);
}

std::shared_ptr<IReaderJson> ReaderJson::GetObject(const std::string& key) const
{
	const auto optional = m_impl->m_pt.get_child_optional(key);

	if (!optional.has_value())
		return nullptr;

	auto impl = std::make_unique<Impl>();

	impl->m_pt = optional.get();

	return std::shared_ptr<ReaderJson>(new ReaderJson(std::move(impl)));
}

bool ReaderJson::IsContains(const std::string& key) const
{
	return m_impl->m_pt.find(key) != m_impl->m_pt.not_found();
}

bool ReaderJson::IsEmpty() const
{
	return m_impl->m_pt.empty();
}

ReaderJson::ReaderJson(std::unique_ptr<Impl>&& impl)
	: m_impl(std::move(impl))
{
}
