#include "StandartStreamsWrapper.h"

using namespace PasswordKit;

namespace {
	const std::string END_STRING = "End";
}


std::string StandartStreamsWrapper::WaitData()
{
	std::string message;

	if(std::getline(std::cin, message))
	{
		if (message == GetFinishStatus() || std::cin.eof())
			return GetFinishStatus();

		return message;
	}

	return GetFinishStatus();
}

void StandartStreamsWrapper::PushData(const std::string& data)
{
	std::cout << data;
}

const std::string& StandartStreamsWrapper::GetFinishStatus()
{
	return END_STRING;
}
