#include <stdexcept>

#include <boost/program_options.hpp>

#include "CommandLineParser.h"

using namespace Tools;

namespace
{
	template <class T>

	T Get(const std::string& key, const boost::program_options::variables_map& map)
	{
		if (map.count(key) == 0)
			throw std::logic_error("Options not found.");

		const auto t = map[key].value().type().name();

		return map[key].as<T>();
	}
}

struct CommandLineParser::Impl
{
	std::string m_currentPath;

	boost::program_options::options_description m_des;
	boost::program_options::variables_map m_vm;
};

CommandLineParser::CommandLineParser()
	: m_impl(std::make_unique<Impl>())
{
}

CommandLineParser::~CommandLineParser() = default;

void CommandLineParser::AddInt(const std::string & name, const std::string & description) const
{
	m_impl->m_des.add_options()(name.c_str(), boost::program_options::value<int>()->required(), description.c_str());
}

void CommandLineParser::AndString(const std::string& name, const std::string& description) const
{
	m_impl->m_des.add_options()(name.c_str(), boost::program_options::value<std::string>()->required(), description.c_str());
}

void CommandLineParser::Parse(int argc, const char* argv[])
{
	if (argc < 1)
		throw std::logic_error("Invalid count of arguments.");

	m_impl->m_currentPath = argv[0];

	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, m_impl->m_des), m_impl->m_vm);

	notify(m_impl->m_vm);
}

std::string CommandLineParser::GetCurrentDir() const
{
	return m_impl->m_currentPath;
}

bool CommandLineParser::Contains(const std::string& key) const
{
	return m_impl->m_vm.count(key) != 0;
}

int CommandLineParser::GetInt(const std::string& name) const
{
	return Get<int>(name, m_impl->m_vm);
}

std::string CommandLineParser::GetString(const std::string& name) const
{
	return Get<std::string>(name, m_impl->m_vm);
}
