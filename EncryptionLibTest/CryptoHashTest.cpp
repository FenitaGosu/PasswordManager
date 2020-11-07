#include <algorithm>
#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "EncryptionLib/Interfaces/ICryptoHash.h"
#include "EncryptionLib/CryptoHash/CryptoHash.h"

using namespace Encryption;

TEST(CryptoHashTest, MD5EmptyTextTest)
{
	CryptoHash hashGenertor;

	const auto a = hashGenertor.GetMd5("");
	ASSERT_EQ(hashGenertor.GetMd5(""), "d41d8cd98f00b204e9800998ecf8427e");
}
