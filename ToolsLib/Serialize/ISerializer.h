#pragma once

#include <string>
#include <memory>

namespace Tools {

	class ISerializer
	{
	public:
		virtual ~ISerializer() = default;

		virtual void AddBool	(const std::string& key, bool value) = 0;
		virtual void AddDouble	(const std::string& key, double value) = 0;
		virtual void AddInt		(const std::string& key, int value) = 0;
		virtual void AddString	(const std::string& key, const std::string& value) = 0;
		virtual void AddObject	(const std::string& key, const std::shared_ptr<ISerializer>& object) = 0;

		virtual std::string Serialize() const = 0;
	};
}
