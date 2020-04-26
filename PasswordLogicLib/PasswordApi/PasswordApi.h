#pragma once

#include "PasswordGeneratorLib/Interfaces/IPasswordGenerator.h"

#include "PasswordLogicLib/Interfaces/IPasswordApi.h"
#include "PasswordLogicLib/Interfaces/ICredentialsInspector.h"
#include "PasswordLogicLib/Interfaces/IDataController.h"


namespace PasswordLogic {

	class PasswordApi : public IPasswordApi
	{
	public:
		PasswordApi(
			std::unique_ptr<PasswordLogic::ICredentialsInspector>&&		credentialIncpector,
			std::unique_ptr<PasswordLogic::IDataController>&&			dataController,
			std::unique_ptr<PasswordGenerator::IPasswordGenerator>&&	passwordGenerator
		);

		~PasswordApi();

		std::vector<std::string> GeneratePasswordsByParams(const std::vector<PasswordGenerator::ComponentsOfPassword>& settings, size_t length, size_t count) const override;

		bool NeedToSetMainPassword() const override;
		bool EnterMainPassword(const std::string& password) const override;
		void SetMainPassword(const std::string& password, const std::string& newPassword) override;

		std::vector<AccountInfo> GetAllAccountsInfo() const override;
		void AddNewAccount(const AccountInfo& info) override;

	private:
		std::unique_ptr<PasswordLogic::ICredentialsInspector>	m_credentialIncpector;
		std::unique_ptr<PasswordLogic::IDataController>			m_dataController;
		std::unique_ptr<PasswordGenerator::IPasswordGenerator>	m_passwordGenerator;
		mutable bool m_accessIsAllowed;
	};
}
