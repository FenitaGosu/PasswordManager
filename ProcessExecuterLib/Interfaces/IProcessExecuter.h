#pragma once

#include <string>
#include <vector>

namespace ProcessExecuter {

	class IProcessExecuter
	{
	public:
		~IProcessExecuter() = default;

		virtual void RunProcess(const std::string& path, const std::vector<std::string>& arguments = {}) = 0;
		virtual void StopProcess() = 0;
		virtual bool IsRunning() const = 0;

		virtual void WriteToStandartInput(const std::string& data) = 0;
		virtual std::string ReadFromStandartOutput() = 0;
	};

}
