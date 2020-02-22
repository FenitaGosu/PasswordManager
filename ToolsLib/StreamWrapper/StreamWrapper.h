#pragma once

#include <iostream>
#include <string>

namespace Tools {

class StreamWrapper
{
public:
	StreamWrapper(std::istream& input, std::ostream& output);

	template <typename Arg, typename... Args>
	void Write(const std::string& separator, Arg&& arg, Args&& ... args)
	{
		m_output << std::forward<Arg>(arg);
		((m_output << separator << std::forward<Args>(args)), ...);
	}

	template <typename Arg, typename... Args>
	void Read(Arg&& arg, Args&& ... args)
	{
		m_input >> std::forward<Arg>(arg);
		((m_input >> std::forward<Args>(args)), ...);
	}

private:
	std::istream& m_input;
	std::ostream& m_output;
};

}
