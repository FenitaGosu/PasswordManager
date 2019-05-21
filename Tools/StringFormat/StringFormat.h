#pragma once

#include <string>

namespace Tools {

class StringFormat
{
public:
	template<typename ... Args>
	static std::string Format(const std::string& format, Args ... args)
	{
		const auto size = snprintf(nullptr, 0, format.c_str(), std::forward<Args>(args) ...) + 1;
		auto* buf = new char[size];

		snprintf(buf, size, format.c_str(), std::forward<Args>(args) ...);
		const auto res = std::string(buf, buf + size - 1);

		delete[] buf;

		return res;
	}
};

}