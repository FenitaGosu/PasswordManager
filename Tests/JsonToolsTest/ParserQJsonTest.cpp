#include <memory>
#include <exception>

#include <QFile>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "JsonTools/ParserQJson/ParserQJson.h"

TEST(ParserQJsonTest, OpenEmptyJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/Empty.json"));
}

TEST(ParserQJsonTest, OpenIncorrectJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/Incorrect.json"));
}

TEST(ParserQJsonTest, OpenNotMainSectionJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/NotMainSection.json"));
}

TEST(ParserQJsonTest, OpenNotExeptionJson)
{
	ASSERT_NO_THROW(std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/Values.json"));
}

TEST(ParserQJsonTest, ParseDoubleJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/Values.json");
	ASSERT_DOUBLE_EQ(parser->GetDouble("Double"), 1.50);
}

TEST(ParserQJsonTest, ParseIntJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/Values.json");
	ASSERT_EQ(parser->GetInt("Int"), 100);
}

TEST(ParserQJsonTest, ParseBoolJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/Values.json");
	ASSERT_EQ(parser->GetBool("Bool"), true);
}

TEST(ParserQJsonTest, ParseStringJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/Values.json");
	ASSERT_EQ(parser->GetString("String"), "test");
}

TEST(ParserQJsonTest, ParseObjectJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/JsonToolsTest/Values.json");;
	ASSERT_EQ(parser->GetObject("Object")->GetString("String"), "test");
}
