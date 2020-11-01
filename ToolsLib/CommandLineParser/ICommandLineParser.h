#pragma once

#include <string>
#include <vector>

namespace Tools {

	class ICommandLineParser
	{
	public:
		virtual ~ICommandLineParser() = default;

		virtual void Parse(int argc, const char* argv[]) = 0;

		virtual std::string GetCurrentDir() const = 0;

		virtual bool Contains(const std::string& key) const = 0;

		virtual void AddInt(const std::string& name, const std::string& description) const = 0;
		virtual void AndString(const std::string& name, const std::string& description) const = 0;

		virtual int GetInt(const std::string& name) const = 0;
		virtual std::string GetString(const std::string& name) const = 0;
	};
}
