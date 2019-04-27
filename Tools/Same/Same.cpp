#include "Same.h"

using namespace Tools;

Same::Same(int v)
	: m_value(v)
{
}

Same::Same(bool v)
	: m_value(v)
{
}

Same::Same(double v)
	: m_value(v)
{
}

Same::Same(std::string v)
	: m_value(v)
{
}

bool Same::HasValue() const noexcept
{
	return m_value.has_value();
}

int Same::ToInt() const
{
	return Get<int>();
}

bool Same::ToBool() const
{
	return Get<bool>();
}

double Same::ToDouble() const
{
	return Get<double>();
}

std::string Same::ToString() const
{
	return Get<std::string>();
}
