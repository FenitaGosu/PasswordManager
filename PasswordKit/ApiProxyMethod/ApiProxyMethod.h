#pragma once

#include <string>

#include "ToolsLib/Serialize/ISerializeFactory.h"

#include "ToolsLib/Serialize/IDeserializer.h"
#include "ToolsLib/Serialize/ISerializer.h"

#include "PasswordKit/Interfaces/IApiProxyMethod.h"

namespace PasswordKit {

	template <class MethodInfo, class ApiProxyMethodExecuter>
	class ApiProxyMethod : public IApiProxyMethod
	{
	public:
		ApiProxyMethod(const Tools::ISerializeFactory& serializer, const ApiProxyMethodExecuter& executer)
			: m_serializer(serializer)
			, m_executer(executer)
		{
		}

		const std::string& GetName() const noexcept override
		{
			return MethodInfo::NAME;
		}

		std::shared_ptr<Tools::ISerializer> Do(const std::shared_ptr<Tools::IDeserializer>& deserializer) const override
		{
			MethodInfo::InputParameters input;

			MethodInfo::Dserialize(input, deserializer);

			const MethodInfo::OutputParameters output = m_executer.Do(input);

			const std::shared_ptr<Tools::ISerializer> serializer = m_serializer.CreateISerializer();

			MethodInfo::Serialize(output, serializer);

			return serializer;
		}

	private:
		const Tools::ISerializeFactory& m_serializer;
		const ApiProxyMethodExecuter	m_executer;
	};
}
