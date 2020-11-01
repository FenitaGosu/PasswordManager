#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ToolsLib/CommandLineParser/CommandLineParser.h"

namespace {

	std::shared_ptr<Tools::ICommandLineParser> CreateParser()
	{
		return std::make_shared<Tools::CommandLineParser>();
	}
}

TEST(CommandLineParserTest, InvalidCountOfArguments)
{
	const auto ptrParser = CreateParser();

	const char* args;

	ASSERT_ANY_THROW(ptrParser->Parse(0, &args));
}


TEST(CommandLineParserTest, CommandLineOnlyPath)
{
	const auto ptrParser = CreateParser();

	const char* args[] = { "currentPath" };

	ptrParser->Parse(1, args);

	ASSERT_EQ(ptrParser->GetCurrentDir(), "currentPath");
}

TEST(CommandLineParserTest, GetString)
{
	const auto ptrParser = CreateParser();

	const char* args[] = { "currentPath", "--MyString", "STRING" };

	ptrParser->AndString("MyString", "blabla");

	ptrParser->Parse(3, args);

	ASSERT_EQ(ptrParser->GetString("MyString"), "STRING");
}

TEST(CommandLineParserTest, GetInt)
{
	const auto ptrParser = CreateParser();

	const char* args[] = { "currentPath", "--MyInt", "5" };

	ptrParser->AddInt("MyInt", "blabla");

	ptrParser->Parse(3, args);

	ASSERT_EQ(ptrParser->GetInt("MyInt"), 5);
}
