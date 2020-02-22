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
	Same(const std::string& v);

	bool HasValue() const noexcept;

	int					ToInt() const;
	bool				ToBool() const;
	double				ToDouble() const;
	const std::string&	ToString() const;

	template<typename T>
	void Set(const T& v)
	{
		m_value = v;
	}

	template<typename T>
	const T& Get() const
	{
		return std::any_cast<const T&>(m_value);
	}

	template<typename T>
	T& GetRef()
	{
		return std::any_cast<T&>(m_value);
	}

	template<typename T>
	static Same FromValue(const T& v)
	{
		Same s;
		s.Set(v);
		return s;
	}

private:
	std::any m_value;
};

}
