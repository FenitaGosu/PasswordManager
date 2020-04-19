#pragma once

#include <string>
#include <memory>

#include "ToolsLib/Serialize/ISerializeFactory.h"
#include "ToolsLib/Serialize/IDeserializer.h"
#include "ToolsLib/Serialize/ISerializer.h"

#include "ApiProxyLib/Interfaces/IApiProxyMethod.h"

namespace Proxy {

	template <class MethodInfo, class ApiProxyMethodExecuter>
	class ApiProxyMethod : public IApiProxyMethod
	{
	public:
		ApiProxyMethod(const std::shared_ptr<Tools::ISerializeFactory>& serializeFactory, const std::shared_ptr<ApiProxyMethodExecuter>& executer)
			: m_serializeFactory(serializeFactory)
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

			const MethodInfo::OutputParameters output = m_executer->Do(input);

			const std::shared_ptr<Tools::ISerializer> serializer = m_serializeFactory->CreateISerializer();

			MethodInfo::Serialize(output, serializer);

			return serializer;
		}

	private:
		std::shared_ptr<Tools::ISerializeFactory>	m_serializeFactory;
		std::shared_ptr<ApiProxyMethodExecuter>		m_executer;
	};
}
