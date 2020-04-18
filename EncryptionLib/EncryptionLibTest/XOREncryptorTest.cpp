#include <algorithm>
#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "EncryptionLib/Interfaces/IEncryptor.h"
#include "EncryptionLib/Interfaces/IKeyProvider.h"
#include "EncryptionLib/XOREncryptor/XOREncryptor.h"
#include "EncryptionLib/SimpleKeyProvider/SimpleKeyProvider.h"

using namespace Encryption;

TEST(XOREncryptorTest, NormalTest)
{
	XOREncryptor enctyptor(std::make_unique<SimpleKeyProvider>("super Key"));

	const auto original = "privet mir";
	ASSERT_EQ(enctyptor.Decrypt(enctyptor.Encrypt(original)), original);
}

TEST(XOREncryptorTest, EmptyStringTest)
{
	XOREncryptor enctyptor(std::make_unique<SimpleKeyProvider>("super Key"));
	const auto original = "";
	ASSERT_EQ(enctyptor.Decrypt(enctyptor.Encrypt(original)), original);
}

TEST(XOREncryptorTest, EmptyKeyEncryptTest)
{
	XOREncryptor enctyptor(std::make_unique<SimpleKeyProvider>(""));
	const auto original = "privet mir";
	ASSERT_ANY_THROW(enctyptor.Encrypt(original));
}

TEST(XOREncryptorTest, EmptyKeyDecryptTest)
{
	XOREncryptor enctyptor(std::make_unique<SimpleKeyProvider>(""));
	const auto original = "privet mir";
	ASSERT_ANY_THROW(enctyptor.Decrypt(original));
}
