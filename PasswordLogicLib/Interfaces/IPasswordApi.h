#pragma once

#include <string>
#include <vector>

#include "PasswordGeneratorLib/Enums/ComponentsOfPassword.h"

#include "PasswordLogicLib/AccountInfo/AccountInfo.h"

namespace PasswordLogic {

	class IPasswordApi
	{
	public:
		virtual ~IPasswordApi() = default;

	/// passwords generator api
	public:
		virtual std::vector<std::string> GeneratePasswordsByParams(const std::vector<PasswordGenerator::ComponentsOfPassword>& settings, size_t length, size_t count) const = 0;

	/// authorization api
	public:
		virtual	bool NeedToSetMainPassword() const = 0;
		virtual bool EnterMainPassword(const std::string& password) const = 0;
		virtual void SetMainPassword(const std::string& password) = 0;

	/// paswords library api
	public:
		virtual std::vector<AccountInfo> GetAllAccountsInfo() const = 0;
		virtual void AddNewAccount(const AccountInfo& info) = 0;
	};
}
