#include <stdexcept>

#include "PasswordApi.h"

using namespace PasswordLogic;

namespace {
	const std::string ACCESS_DENIED = "Access_denied.";
}

PasswordApi::PasswordApi(std::unique_ptr<PasswordLogic::ICredentialsInspector>&& credentialIncpector, std::unique_ptr<PasswordLogic::IDataController>&& dataController, std::unique_ptr<PasswordGenerator::IPasswordGenerator>&& passwordGenerator)
	: m_credentialIncpector(std::move(credentialIncpector))
	, m_dataController(std::move(dataController))
	, m_passwordGenerator(std::move(passwordGenerator))
	, m_accessIsAllowed(false)
{
}

PasswordApi::~PasswordApi() = default;

std::vector<std::string> PasswordApi::GeneratePasswordsByParams(const std::vector<PasswordGenerator::ComponentsOfPassword>& settings, size_t length, size_t count) const
{
	return m_passwordGenerator->Generate(settings, length, count);
}

bool PasswordApi::NeedToSetMainPassword() const
{
	return m_credentialIncpector->IsNeedSetPassword();
}

bool PasswordApi::EnterMainPassword(const std::string& password) const
{
	m_accessIsAllowed = m_credentialIncpector->CheckPassword(password);
	return m_accessIsAllowed;
}

void PasswordApi::SetMainPassword(const std::string& password, const std::string& newPassword)
{
	if (EnterMainPassword(password))
		m_credentialIncpector->SetPassword(newPassword);
	else
		throw std::runtime_error(ACCESS_DENIED);
}

std::vector<AccountInfo> PasswordApi::GetAllAccountsInfo() const
{
	if (m_accessIsAllowed)
		return m_dataController->GetAccountsInfo();
	else
		throw std::runtime_error(ACCESS_DENIED);
}

void PasswordApi::AddNewAccount(const AccountInfo& info)
{
	if (m_accessIsAllowed)
		return m_dataController->AddNewAccount(info);
	else
		throw std::runtime_error(ACCESS_DENIED);
}
