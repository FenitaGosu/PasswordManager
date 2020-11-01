#include <memory>
#include <exception>
#include <fstream>
#include <streambuf>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "JsonToolsLib/ReaderJson/ReaderJson.h"

namespace {
	std::string ReadFile(const std::string& path)
	{
		std::ifstream input(path);

		if (!input.is_open())
			throw std::logic_error("File is not found.");

		std::string str((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

		return str;
	}
}

TEST(ReaderJsonTest, OpenEmptyJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ReaderJson>(ReadFile("Empty.json")));
}

TEST(ReaderJsonTest, OpenNotExeptionJson)
{
	ASSERT_NO_THROW(std::make_unique<JsonTools::ReaderJson>(ReadFile("Values.json")));
}

TEST(ReaderJsonTest, OpenIncorrectJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ReaderJson>(ReadFile("Incorrect.json")));
}

TEST(ReaderJsonTest, OpenNotMainSectionJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ReaderJson>(ReadFile("NotMainSection.json")));
}

TEST(ReaderJsonTest, ParseObjectJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderJson>(ReadFile("Values.json"));
	ASSERT_EQ(parser->GetObject("Object")->GetString("String"), "test");
}

TEST(ReaderJsonTest, ParseDoubleJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderJson>(ReadFile("Values.json"));
	ASSERT_DOUBLE_EQ(parser->GetDouble("Double"), 1.50);
}

TEST(ReaderJsonTest, ContainsJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderJson>(ReadFile("Values.json"));
	ASSERT_EQ(parser->IsContains("BlaBla"), false);
}

TEST(ReaderJsonTest, ParseIntJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderJson>(ReadFile("Values.json"));
	ASSERT_EQ(parser->GetInt("Int"), 100);
}

TEST(ReaderJsonTest, ParseBoolJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderJson>(ReadFile("Values.json"));
	ASSERT_EQ(parser->GetBool("Bool"), true);
}

TEST(ReaderJsonTest, ParseStringJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderJson>(ReadFile("Values.json"));
	ASSERT_EQ(parser->GetString("String"), "test");
}
