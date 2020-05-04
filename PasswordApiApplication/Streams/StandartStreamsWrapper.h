#pragma once

#include <iostream>

#include "PasswordApiApplication/Interfaces/IDataStream.h"

namespace PasswordKit {

	class StandartStreamsWrapper : public IDataStream
	{
	public:

		std::string WaitData() override;
		void PushData(const std::string& data) override;

		const std::string& GetFinishStatus() override;
	};

}
