#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Tools/StringFormat/StringFormat.h"

TEST(StringFormatTest, StringArguments)
{
	const std::string str = "Hello %s %s world!";
	const std::string res = "Hello my new world!";

	ASSERT_EQ(Tools::StringFormat::Format(str, "my", "new"), res);
}

TEST(StringFormatTest, IntegerArguments)
{
	const std::string str = "Hello %i %i world!";
	const std::string res = "Hello 4 5 world!";

	ASSERT_EQ(Tools::StringFormat::Format(str, 4, 5), res);
}
