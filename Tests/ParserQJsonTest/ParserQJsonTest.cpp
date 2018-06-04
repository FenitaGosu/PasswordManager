#include <memory>
#include <exception>

#include <QFile>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "JsonTools/ParserQJson/ParserQJson.h"

TEST(QJsonImplTest, OpenEmptyJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/Empty.json"));
}

TEST(QJsonImplTest, OpenIncorrectJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/Incorrect.json"));
}

TEST(QJsonImplTest, OpenNotMainSectionJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/NotMainSection.json"));
}

TEST(QJsonImplTest, OpenNotExeptionJson)
{
	ASSERT_NO_THROW(std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/Values.json"));
}

TEST(QJsonImplTest, ParseDoubleJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/Values.json");
	ASSERT_DOUBLE_EQ(parser->GetDouble("Double"), 1.50);
}

TEST(QJsonImplTest, ParseIntJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/Values.json");
	ASSERT_EQ(parser->GetInt("Int"), 100);
}

TEST(QJsonImplTest, ParseBoolJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/Values.json");
	ASSERT_EQ(parser->GetBool("Bool"), true);
}

TEST(QJsonImplTest, ParseStringJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/Values.json");
	ASSERT_EQ(parser->GetString("String"), "test");
}

TEST(QJsonImplTest, ParseObjectJson)
{
	const auto parser = std::make_unique<JsonTools::ParserQJson>(":/ParserQJsonTest/Values.json");;
	ASSERT_EQ(parser->GetObject("Object")->GetString("String"), "test");
}
