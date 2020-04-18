#pragma once

#include <memory>

#include "ISerializer.h"
#include "IDeserializer.h"

namespace Tools {

	class ISerializeFactory
	{
	public:
		~ISerializeFactory() = default;

		virtual std::shared_ptr<IDeserializer>	CreateDeserializer(const std::string& str) const = 0;
		virtual std::shared_ptr<ISerializer>	CreateISerializer() const = 0;
	};

}
