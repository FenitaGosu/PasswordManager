#pragma once

#include <string>
#include <memory>

namespace Tools {

	class IDeserializer
	{
	public:
		virtual ~IDeserializer() = default;

		virtual bool							GetBool(const std::string& key, const bool defaultValue = false) const = 0;
		virtual double							GetDouble(const std::string& key, const double defaultValue = 0.) const = 0;
		virtual int								GetInt(const std::string& key, const int defaultValue = 0.) const = 0;
		virtual std::string						GetString(const std::string& key, const std::string& defaultValue = std::string()) const = 0;
		virtual std::shared_ptr<IDeserializer>	GetObject(const std::string& key) const = 0;

		virtual bool IsContains(const std::string& key) const = 0;
		virtual bool IsEmpty() const = 0;
	};

}
