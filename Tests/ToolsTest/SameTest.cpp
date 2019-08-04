#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Tools/Same/Same.h"

TEST(SameTest, Int)
{
	{
		const auto sameInt = Tools::Same::FromValue(100);

		ASSERT_EQ(sameInt.ToInt(), 100);
		ASSERT_EQ(sameInt.Get<int>(), 100);
	}

	{
		const Tools::Same sameInt(100);

		ASSERT_EQ(sameInt.ToInt(), 100);
		ASSERT_EQ(sameInt.Get<int>(), 100);
	}

	{
		Tools::Same sameInt;

		sameInt.Set(100);

		ASSERT_EQ(sameInt.ToInt(), 100);
		ASSERT_EQ(sameInt.Get<int>(), 100);
	}
}

TEST(SameTest, Bool)
{
	{
		const auto sameBool = Tools::Same::FromValue(true);

		ASSERT_EQ(sameBool.ToBool(), true);
		ASSERT_EQ(sameBool.Get<bool>(), true);
	}

	{
		const Tools::Same sameBool(true);

		ASSERT_EQ(sameBool.ToBool(), true);
		ASSERT_EQ(sameBool.Get<bool>(), true);
	}

	{
		Tools::Same sameBool;

		sameBool.Set(true);

		ASSERT_EQ(sameBool.ToBool(), true);
		ASSERT_EQ(sameBool.Get<bool>(), true);
	}
}

TEST(SameTest, Double)
{
	{
		const auto sameDouble = Tools::Same::FromValue(100.56789);

		ASSERT_DOUBLE_EQ(sameDouble.ToDouble(), 100.56789);
		ASSERT_DOUBLE_EQ(sameDouble.Get<double>(), 100.56789);
	}

	{
		const Tools::Same sameDouble(100.56789);

		ASSERT_DOUBLE_EQ(sameDouble.ToDouble(), 100.56789);
		ASSERT_DOUBLE_EQ(sameDouble.Get<double>(), 100.56789);
	}

	{
		Tools::Same sameDouble;

		sameDouble.Set(100.56789);

		ASSERT_DOUBLE_EQ(sameDouble.ToDouble(), 100.56789);
		ASSERT_DOUBLE_EQ(sameDouble.Get<double>(), 100.56789);
	}
}

TEST(SameTest, String)
{
	{
		const auto sameString = Tools::Same::FromValue(std::string("TestString"));

		ASSERT_EQ(sameString.ToString(), "TestString");
		ASSERT_EQ(sameString.Get<std::string>(), "TestString");
	}

	{
		const Tools::Same sameString(std::string("TestString"));

		ASSERT_EQ(sameString.ToString(), "TestString");
		ASSERT_EQ(sameString.Get<std::string>(), "TestString");
	}

	{
		Tools::Same sameString;

		sameString.Set(std::string("TestString"));

		ASSERT_EQ(sameString.ToString(), "TestString");
		ASSERT_EQ(sameString.Get<std::string>(), "TestString");
	}
}

TEST(SameTest, GetRef)
{
	Tools::Same sameString(std::string("TestString"));

	ASSERT_EQ(sameString.ToString(), "TestString");

	sameString.GetRef<std::string>() = "NewTestString";

	ASSERT_EQ(sameString.ToString(), "NewTestString");
}
