#include "CredentialsInspector.h"

using namespace PasswordLogic;

CredentialsInspector::CredentialsInspector()
	: m_password("password")
{
}

bool CredentialsInspector::IsFirstStart() const
{
	return true;
}

bool CredentialsInspector::CheckPassword(const std::string& password) const
{
	return m_password == password;
}

void CredentialsInspector::SetPassword(const std::string& password)
{
	m_password = password;
}
