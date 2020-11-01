#include <memory>
#include <exception>

#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "JsonToolsLib/ReaderJson/ReaderJson.h"
#include "JsonToolsLib/WriterJson/WriterJson.h"


TEST(WriterJsonTest, WriteEmptyJson)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	std::unique_ptr<JsonTools::IReaderJson> reader;

	ASSERT_NO_THROW(reader = std::make_unique<JsonTools::ReaderJson>(writer->Serialize()));
	ASSERT_TRUE(reader->IsEmpty());
}

TEST(WriterJsonTest, WriteBoolValue)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddBool("VALUE", true));

	const auto reader = std::make_unique<JsonTools::ReaderJson>(writer->Serialize());

	ASSERT_EQ(reader->GetBool("VALUE", false), true);
}

TEST(WriterJsonTest, WriteBoolValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddBool("VALUE", true));
	ASSERT_ANY_THROW(writer->AddBool("VALUE", true));
}

TEST(WriterJsonTest, WriteIntValue)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddInt("VALUE", 100));

	const auto reader = std::make_unique<JsonTools::ReaderJson>(writer->Serialize());

	ASSERT_EQ(reader->GetInt("VALUE", 200), 100);
}

TEST(WriterJsonTest, WriteIntValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddInt("VALUE", 100));
	ASSERT_ANY_THROW(writer->AddInt("VALUE", 100));
}

TEST(WriterJsonTest, WriteDoubleValue)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddDouble("VALUE", 100.0));

	const auto reader = std::make_unique<JsonTools::ReaderJson>(writer->Serialize());

	ASSERT_DOUBLE_EQ(reader->GetDouble("VALUE", 200.0), 100.0);
}

TEST(WriterJsonTest, WriteDoubleValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddDouble("VALUE", 100.0));
	ASSERT_ANY_THROW(writer->AddDouble("VALUE", 100.0));
}

TEST(WriterJsonTest, WriteStringValue)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddString("VALUE", "TEST_STRING"));

	const auto reader = std::make_unique<JsonTools::ReaderJson>(writer->Serialize());

	ASSERT_EQ(reader->GetString("VALUE", "NO_TEST_STRING"), "TEST_STRING");
}

TEST(WriterJsonTest, WriteStringValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddString("VALUE", "TEST_STRING"));
	ASSERT_ANY_THROW(writer->AddString("VALUE", "TEST_STRING"));
}

TEST(WriterJsonTest, WriteObjectValue)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();
	const auto object = std::make_shared<JsonTools::WriterJson>();
	const auto emptyObject = std::make_shared<JsonTools::WriterJson>();

	object->AddBool		("VALUE_BOOL"		, true);
	object->AddInt		("VALUE_INT"		, 100);
	object->AddDouble	("VALUE_DOUBLE"		, 200.0);
	object->AddString	("VALUE_STRIG"		, "TEST_STRING");

	ASSERT_NO_THROW(writer->AddObject("VALUE", object));

	const auto reader = std::make_unique<JsonTools::ReaderJson>(writer->Serialize());
	const auto testObject = reader->GetObject("VALUE");

	ASSERT_EQ			(testObject->GetBool	("VALUE_BOOL"	, false)			, true);
	ASSERT_EQ			(testObject->GetInt		("VALUE_INT"	, 200)				, 100);
	ASSERT_DOUBLE_EQ	(testObject->GetDouble	("VALUE_DOUBLE"	, 100.0)			, 200.0);
	ASSERT_EQ			(testObject->GetString	("VALUE_STRIG"	, "NO_TEST_STRING")	, "TEST_STRING");
}

TEST(WriterJsonTest, WriteObjectValueThrow)
{
	const auto writer = std::make_unique<JsonTools::WriterJson>();
	const auto object = std::make_shared<JsonTools::WriterJson>();

	ASSERT_NO_THROW(writer->AddObject("VALUE", object));
	ASSERT_ANY_THROW(writer->AddObject("VALUE", object));
}
