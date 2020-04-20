#pragma once

#include <memory>

#include "ToolsLib/Serialize/ISerializer.h"
#include "ToolsLib/Serialize/IDeserializer.h"

namespace PasswordLogicApiInfo {

	class SetMainPasswordMethodInfo;

/**************************************************************************************************/

#define BEGIN_CLASS_METHOD_INFO(FunctionName)						\
		class FunctionName##MethodInfo								\
		{															\
		public:														\
			inline static const std::string NAME = #FunctionName;	\
																	\
		public:														\

#define END_CLASS_METHOD_INFO(FunctionName)							\
		public:																																		\
			static void	Serialize(const FunctionName##MethodInfo::InputParameters& value, const std::shared_ptr<Tools::ISerializer>& serializer);	\
			static void	Dserialize(FunctionName##MethodInfo::InputParameters& value, const std::shared_ptr<Tools::IDeserializer>& deserializer);	\
																																					\
			static void	Serialize(const FunctionName##MethodInfo::OutputParameters& value, const std::shared_ptr<Tools::ISerializer>& serializer);	\
			static void	Dserialize(FunctionName##MethodInfo::OutputParameters& value, const std::shared_ptr<Tools::IDeserializer>& deserializer);	\
		};

#define INPUT_PARAMETERES	struct InputParameters {

#define OUTPUT_PARAMETERES	struct OutputParameters {

#define END_PARAMETERES		};

/**************************************************************************************************/

	BEGIN_CLASS_METHOD_INFO(SetMainPassword)
		INPUT_PARAMETERES
			std::string password;
			std::string newPassword;
		END_PARAMETERES

		OUTPUT_PARAMETERES
		END_PARAMETERES
	END_CLASS_METHOD_INFO(SetMainPassword)

/**************************************************************************************************/

#undef BEGIN_CLASS_METHOD_INFO
#undef END_CLASS_METHOD_INFO
#undef INPUT_PARAMETERES
#undef OUTPUT_PARAMETERES
#undef END_PARAMETERES

}
