#include "PasswordLogicApiInfoLib/ApiParameters.h"

#include "ApiProxyMethodExecuter.h"

using namespace PasswordLogicApiInfo;

namespace PasswordKit {
	
	template<>
	SetMainPasswordMethodInfo::OutputParameters ApiProxyMethodExecuter<SetMainPasswordMethodInfo>::Do(const SetMainPasswordMethodInfo::InputParameters& inputParameters) const
	{
		/// todo use m_api
		return SetMainPasswordMethodInfo::OutputParameters();
	}

}
