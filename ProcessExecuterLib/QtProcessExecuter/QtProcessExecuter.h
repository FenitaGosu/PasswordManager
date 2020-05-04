#pragma once

#include <memory>

#include "ProcessExecuterLib/Interfaces/IProcessExecuter.h"

class QProcess;

namespace ProcessExecuter {

	class QtProcessExecuter : public IProcessExecuter
	{
	public:
		QtProcessExecuter();
		~QtProcessExecuter();

		void RunProcess(const std::string& path, const std::vector<std::string>& arguments = {}) override;
		void StopProcess() override;
		bool IsRunning() const override;

		void WriteToStandartInput(const std::string& data) override;
		std::string ReadFromStandartOutput() override;

	private:
		std::unique_ptr<QProcess> m_process;
	};
}
