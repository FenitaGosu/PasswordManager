#include "PasswordApi.h"

using namespace PasswordLogic;

PasswordApi::PasswordApi(std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector, std::unique_ptr<PasswordLogic::IDataController>&& dataController, std::unique_ptr<PasswordGenerator::IPasswordGenerator>&& passwordGenerator)
	: m_credentialIncpector(std::move(credentialIncpector))
	, m_dataController(std::move(dataController))
	, m_passwordGenerator(std::move(passwordGenerator))
{
}

PasswordApi::~PasswordApi() = default;

std::vector<std::string> PasswordApi::GeneratePasswordsByParams(const std::vector<PasswordGenerator::ComponentsOfPassword>& settings, size_t length, size_t count) const
{
	return {};
}

bool PasswordApi::NeedToSetMainPassword() const
{
	return false;
}

bool PasswordApi::EnterMainPassword(const std::string& password) const
{
	return false;
}

void PasswordApi::SetMainPassword(const std::string& password, const std::string& newPassword)
{
}

std::vector<AccountInfo> PasswordApi::GetAllAccountsInfo() const
{
	return {};
}

void PasswordApi::AddNewAccount(const AccountInfo& info)
{
}
