#pragma once

#include <string>

namespace PasswordKit {

	class IDataStream
	{
	public:
		virtual ~IDataStream() = default;

		virtual std::string WaitData() = 0;
		virtual void PushData(const std::string& data) = 0;

		virtual const std::string& GetFinishStatus() = 0;
	};

}
