#pragma once

#include <memory>

#include "PasswordLogicLib/Interfaces/IPasswordApi.h"

namespace PasswordKit {

	template <class MethodInfo>
	class ApiProxyMethodExecuter
	{
	public:
		ApiProxyMethodExecuter(const std::shared_ptr<PasswordLogic::IPasswordApi>& api)
			: m_api(api)
		{
		}

		typename MethodInfo::OutputParameters Do(const typename MethodInfo::InputParameters& inputParameters) const;

	private:
		std::shared_ptr<PasswordLogic::IPasswordApi> m_api;
	};

}
