#pragma once

#include "PasswordLogicLib/Interfaces/IPasswordApi.h"

namespace PasswordKit {

	template <class MethodInfo>
	class ApiProxyMethodExecuter
	{
	public:
		ApiProxyMethodExecuter(PasswordLogic::IPasswordApi* api)
			: m_api(api)
		{
		}

		typename MethodInfo::OutputParameters Do(const typename MethodInfo::InputParameters& inputParameters) const;

	private:
		PasswordLogic::IPasswordApi* m_api;
	};

}
