#include "SimpleKeyProvider.h"

using namespace Encryption;

SimpleKeyProvider::SimpleKeyProvider(const std::string& str)
	: m_key(str)
{
}

std::string SimpleKeyProvider::GetStringKey() const
{
	return m_key;
}
