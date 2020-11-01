#pragma once

#include <memory>

#include "ICommandLineParser.h"

namespace Tools {

	class CommandLineParser : public ICommandLineParser
	{
	public:
		CommandLineParser();
		~CommandLineParser();

		void AddInt(const std::string& name, const std::string& description) const override;
		void AndString(const std::string& name, const std::string& description) const override;

		void Parse(int argc, const char* argv[]) override;

		std::string GetCurrentDir() const override;

		bool Contains(const std::string& key) const override;

		int GetInt(const std::string& name) const override;
		std::string GetString(const std::string& name) const override;

	private:
		struct Impl;
		std::unique_ptr<Impl> m_impl;
	};
}
