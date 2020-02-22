#include "EmptyEncryptor.h"

using namespace Encryption;

std::string EmptyEncryptor::Encrypt(const std::string& msg) const
{
	return msg;
}

std::string EmptyEncryptor::Decrypt(const std::string& encryptedMsg) const
{
	return encryptedMsg;
}
