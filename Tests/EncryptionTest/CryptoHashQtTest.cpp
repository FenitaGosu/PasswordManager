#include <algorithm>
#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Encryption/Interfaces/ICryptoHash.h"
#include "Encryption/CryptoHashQt/CryptoHashQt.h"

using namespace Encryption;

TEST(CryptoHashQtTest, MD5EmptyTextTest)
{
	CryptoHashQt hashGenertor;
	ASSERT_EQ(hashGenertor.GetMd5(""), "d41d8cd98f00b204e9800998ecf8427e");
}

TEST(CryptoHashQtTest, MD5NormalTextTest)
{
	CryptoHashQt hashGenertor;
	ASSERT_EQ(hashGenertor.GetMd5("superstr"), "a75a8b11fa9ec2d51ffefd66b528168f");
}

TEST(CryptoHashQtTest, SHA2_256EmptyTextTest)
{
	CryptoHashQt hashGenertor;
	ASSERT_EQ(hashGenertor.GetSha2_256(""), "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
}

TEST(CryptoHashQtTest, SHA2_256NormalTextTest)
{
	CryptoHashQt hashGenertor;
	ASSERT_EQ(hashGenertor.GetSha2_256("superstr"), "926fb153ce7b52601e910a80dd40b5dca1800a983630b95bddbb8f61292516ae");
}

TEST(CryptoHashQtTest, SHA3_256EmptyTextTest)
{
	CryptoHashQt hashGenertor;
	ASSERT_EQ(hashGenertor.GetSha3_256(""), "a7ffc6f8bf1ed76651c14756a061d662f580ff4de43b49fa82d80a4b80f8434a");
}

TEST(CryptoHashQtTest, SHA3_256NormalTextTest)
{
	CryptoHashQt hashGenertor;
	ASSERT_EQ(hashGenertor.GetSha3_256("superstr"), "883eddbffbd83a65d1e30b9e6958532bf4572729baadea6c3f75d478bb6c6ca2");
}
