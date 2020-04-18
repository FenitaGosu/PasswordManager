#pragma once

#include <iostream>

#include "PasswordKit/Interfaces/IDataStream.h"

namespace PasswordKit {

	class StandartStreamsWrapper : public IDataStream
	{
	public:
		StandartStreamsWrapper(std::istream& input, std::ostream& output);

		std::string WaitData() override;
		void PushData(const std::string& data) override;

		const std::string& GetFinishStatus() override;

	private:
		std::istream& m_input;
		std::ostream& m_output;
	};

}
