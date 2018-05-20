#include <memory>
#include <exception>

#include <QFile>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "JsonTools/QJsonImpl/QJsonImpl.h"

TEST(QJsonImplTest, OpenEmptyJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/Empty.json"));
}

TEST(QJsonImplTest, OpenIncorrectJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/Incorrect.json"));
}

TEST(QJsonImplTest, OpenNotMainSectionJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/NotMainSection.json"));
}

TEST(QJsonImplTest, OpenNotExeptionJson)
{
	ASSERT_NO_THROW(std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/Values.json"));
}

TEST(QJsonImplTest, ParseDoubleJson)
{
	const auto parser = std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/Values.json");
	ASSERT_DOUBLE_EQ(parser->GetDouble("Double"), 1.50);
}

TEST(QJsonImplTest, ParseIntJson)
{
	const auto parser = std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/Values.json");
	ASSERT_EQ(parser->GetInt("Int"), 100);
}

TEST(QJsonImplTest, ParseBoolJson)
{
	const auto parser = std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/Values.json");
	ASSERT_EQ(parser->GetBool("Bool"), true);
}

TEST(QJsonImplTest, ParseStringJson)
{
	const auto parser = std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/Values.json");
	ASSERT_EQ(parser->GetString("String"), "test");
}

TEST(QJsonImplTest, ParseObjectJson)
{
	const auto parser = std::make_unique<JsonTools::QJsonImpl>(":/QJsonImplTest/Values.json");;
	ASSERT_EQ(parser->GetObject("Object")->GetString("String"), "test");
}
