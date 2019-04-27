#include "StreamWrapper.h"

using namespace Tools;

StreamWrapper::StreamWrapper(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}
