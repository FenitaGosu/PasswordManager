#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>

#include "ToolsLib/StreamWrapper/StreamWrapper.h"

TEST(StreamWrapperTest, SimpleCreate)
{
	std::istringstream iss;
	std::ostringstream oss;

	ASSERT_NO_THROW(Tools::StreamWrapper(iss, oss));
}

TEST(StreamWrapperTest, Write)
{
	std::istringstream iss;
	std::ostringstream oss;

	Tools::StreamWrapper wrapper(iss, oss);
	
	wrapper.Write(" ", "Hello", 10, "World!");

	ASSERT_EQ(oss.str(), "Hello 10 World!");
}

TEST(StreamWrapperTest, Read)
{
	std::istringstream iss("Hello 10 World!");
	std::ostringstream oss;

	Tools::StreamWrapper wrapper(iss, oss);

	std::string firstString;
	int number;
	std::string secondString;

	wrapper.Read(firstString, number, secondString);
	   
	ASSERT_EQ(firstString, "Hello");
	ASSERT_EQ(number, 10);
	ASSERT_EQ(secondString, "World!");
}