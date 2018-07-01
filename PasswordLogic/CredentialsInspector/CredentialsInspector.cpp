#include "CredentialsInspector.h"

using namespace PasswordLogic;

CredentialsInspector::CredentialsInspector()
{

}

bool CredentialsInspector::IsFirstStart() const
{
	return true;
}

bool CredentialsInspector::CheckPassword() const
{
	return  true;
}

void CredentialsInspector::SetPassword(const std::string& password)
{

}
