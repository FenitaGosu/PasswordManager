#include "StandartStreamsWrapper.h"

using namespace PasswordKit;

namespace {
	const std::string END_STRING = "End";
}

StandartStreamsWrapper::StandartStreamsWrapper(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

std::string StandartStreamsWrapper::WaitData()
{
	std::string message;

	if(std::getline(m_input, message))
	{
		if (message == GetFinishStatus() || m_input.eof())
			return GetFinishStatus();

		return message;
	}
}

void StandartStreamsWrapper::PushData(const std::string& data)
{
	m_output << data;
}

const std::string& StandartStreamsWrapper::GetFinishStatus()
{
	return END_STRING;
}
