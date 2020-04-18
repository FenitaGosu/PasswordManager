#pragma once

#include "ToolsLib/Serialize/ISerializer.h"
#include "ToolsLib/Serialize/IDeserializer.h"

namespace PasswordLogicApiInfo {

	class SetMainPasswordMethodInfo
	{
	public:
		inline static const std::string NAME = "SetMainPassword";

	public:
		struct InputParameters
		{

		};

		struct OutputParameters
		{

		};


	public:
		static void	Serialize(const SetMainPasswordMethodInfo::InputParameters& value, const std::shared_ptr<Tools::ISerializer>& serializer);
		static void	Dserialize(SetMainPasswordMethodInfo::InputParameters& value, const std::shared_ptr<Tools::IDeserializer>& deserializer);

		static void	Serialize(const SetMainPasswordMethodInfo::OutputParameters& value, const std::shared_ptr<Tools::ISerializer>& serializer);
		static void	Dserialize(SetMainPasswordMethodInfo::OutputParameters& value, const std::shared_ptr<Tools::IDeserializer>& deserializer);
	};
}
