#pragma once

#include <string>
#include <memory>

namespace JsonTools {

	/**
	 * Json writer interface
	 */
	class IWriterJson
	{
	public:
		virtual ~IWriterJson() = default;

		virtual void AddBool	(const std::string& key, bool value) = 0;
		virtual void AddDouble	(const std::string& key, double value) = 0;
		virtual void AddInt		(const std::string& key, int value) = 0;
		virtual void AddString	(const std::string& key, const std::string& value) = 0;
		virtual void AddObject	(const std::string& key, const std::shared_ptr<IWriterJson>& object) = 0;

		virtual std::string Serialize() const = 0;
	};
}
