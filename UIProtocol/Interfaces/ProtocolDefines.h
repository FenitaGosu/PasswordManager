#pragma once

namespace UIProtocol {
	
	using MessageHandler = std::pair<std::string, std::function<std::string(const std::string&)>>;

	class MessageType
	{
	public:
		inline static const std::string CHECK_DATA_MESSAGE = "CheckData";
	};
}
