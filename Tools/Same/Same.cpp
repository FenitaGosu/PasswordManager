#include "Same.h"

using namespace Tools;

Same::Same(int v)
	: value(v)
{
}

Same::Same(bool v)
	: value(v)
{
}

Same::Same(double v)
	: value(v)
{
}

Same::Same(std::string v)
	: value(v)
{
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
