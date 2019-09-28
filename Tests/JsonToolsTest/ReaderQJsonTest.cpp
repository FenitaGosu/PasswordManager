#include <memory>
#include <exception>

#include <QFile>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "JsonTools/ReaderQJson/ReaderQJson.h"

namespace {
	std::string ReadFile(const QString& path)
	{
		QFile file(path);
		file.open(QFile::ReadOnly);

		return file.readAll();
	}
}

TEST(ReaderQJsonTest, OpenEmptyJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/Empty.json")));
}

TEST(ReaderQJsonTest, OpenIncorrectJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/Incorrect.json")));
}

TEST(ReaderQJsonTest, OpenNotMainSectionJson)
{
	ASSERT_ANY_THROW(std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/NotMainSection.json")));
}

TEST(ReaderQJsonTest, OpenNotExeptionJson)
{
	ASSERT_NO_THROW(std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/Values.json")));
}

TEST(ReaderQJsonTest, ParseDoubleJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/Values.json"));
	ASSERT_DOUBLE_EQ(parser->GetDouble("Double"), 1.50);
}

TEST(ReaderQJsonTest, ParseIntJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/Values.json"));
	ASSERT_EQ(parser->GetInt("Int"), 100);
}

TEST(ReaderQJsonTest, ParseBoolJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/Values.json"));
	ASSERT_EQ(parser->GetBool("Bool"), true);
}

TEST(ReaderQJsonTest, ParseStringJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/Values.json"));
	ASSERT_EQ(parser->GetString("String"), "test");
}

TEST(ReaderQJsonTest, ParseObjectJson)
{
	const auto parser = std::make_unique<JsonTools::ReaderQJson>(ReadFile(":/JsonToolsTest/Values.json"));
	ASSERT_EQ(parser->GetObject("Object")->GetString("String"), "test");
}
