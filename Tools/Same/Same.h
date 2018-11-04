#pragma once

#include <any>
#include <vector>
#include <string>

namespace Tools {

class Same
{
public:
	Same() = default;

	Same(int v);
	Same(bool v);
	Same(double v);
	Same(std::string v);

	int			ToInt() const;
	bool		ToBool() const;
	double		ToDouble() const;
	std::string	ToString() const;

	template<typename T>
	void Set(const T& v)
	{
		value = v;
	}

	template<typename T>
	T Get() const
	{
		return std::any_cast<T>(value);
	}

private:
	std::any value;
};

}
