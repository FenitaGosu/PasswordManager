#include <memory>
#include <exception>

#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "JsonTools/ReaderQJson/ReaderQJson.h"
#include "JsonTools/WriterQJson/WriterQJson.h"

TEST(WriterQJsonTest, WriteEmptyJson)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	std::unique_ptr<JsonTools::IReaderJson> reader;

	ASSERT_NO_THROW(reader = std::make_unique<JsonTools::ReaderQJson>(writer->Serialize()));
	ASSERT_TRUE(reader->IsEmpty());
}

TEST(WriterQJsonTest, WriteBoolValue)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddBool("VALUE", true));

	const auto reader = std::make_unique<JsonTools::ReaderQJson>(writer->Serialize());

	ASSERT_EQ(reader->GetBool("VALUE", false), true);
}

TEST(WriterQJsonTest, WriteBoolValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddBool("VALUE", true));
	ASSERT_ANY_THROW(writer->AddBool("VALUE", true));
}

TEST(WriterQJsonTest, WriteIntValue)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddInt("VALUE", 100));

	const auto reader = std::make_unique<JsonTools::ReaderQJson>(writer->Serialize());

	ASSERT_EQ(reader->GetInt("VALUE", 200), 100);
}

TEST(WriterQJsonTest, WriteIntValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddInt("VALUE", 100));
	ASSERT_ANY_THROW(writer->AddInt("VALUE", 100));
}

TEST(WriterQJsonTest, WriteDoubleValue)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddDouble("VALUE", 100.0));

	const auto reader = std::make_unique<JsonTools::ReaderQJson>(writer->Serialize());

	ASSERT_DOUBLE_EQ(reader->GetDouble("VALUE", 200.0), 100.0);
}

TEST(WriterQJsonTest, WriteDoubleValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddDouble("VALUE", 100.0));
	ASSERT_ANY_THROW(writer->AddDouble("VALUE", 100.0));
}

TEST(WriterQJsonTest, WriteStringValue)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddString("VALUE", "TEST_STRING"));

	const auto reader = std::make_unique<JsonTools::ReaderQJson>(writer->Serialize());

	ASSERT_EQ(reader->GetString("VALUE", "NO_TEST_STRING"), "TEST_STRING");
}

TEST(WriterQJsonTest, WriteStringValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddString("VALUE", "TEST_STRING"));
	ASSERT_ANY_THROW(writer->AddString("VALUE", "TEST_STRING"));
}

TEST(WriterQJsonTest, WriteObjectValue)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();
	const auto object = std::make_shared<JsonTools::WriterQJson>();
	const auto emptyObject = std::make_shared<JsonTools::WriterQJson>();

	object->AddBool		("VALUE_BOOL"		, true);
	object->AddInt		("VALUE_INT"		, 100);
	object->AddDouble	("VALUE_DOUBLE"		, 200.0);
	object->AddString	("VALUE_STRIG"		, "TEST_STRING");

	ASSERT_NO_THROW(writer->AddObject("VALUE", object));

	const auto reader = std::make_unique<JsonTools::ReaderQJson>(writer->Serialize());
	const auto testObject = reader->GetObject("VALUE");

	ASSERT_EQ			(testObject->GetBool	("VALUE_BOOL"	, false)			, true);
	ASSERT_EQ			(testObject->GetInt		("VALUE_INT"	, 200)				, 100);
	ASSERT_DOUBLE_EQ	(testObject->GetDouble	("VALUE_DOUBLE"	, 100.0)			, 200.0);
	ASSERT_EQ			(testObject->GetString	("VALUE_STRIG"	, "NO_TEST_STRING")	, "TEST_STRING");
}

TEST(WriterQJsonTest, WriteObjectValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterQJson>();
	const auto object = std::make_shared<JsonTools::WriterQJson>();

	ASSERT_NO_THROW(writer->AddObject("VALUE", object));
	ASSERT_ANY_THROW(writer->AddObject("VALUE", object));
}
