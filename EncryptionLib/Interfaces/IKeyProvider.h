#pragma once

#include <string>

namespace Encryption {

class IKeyProvider
{
public:
	virtual ~IKeyProvider() = default;
	virtual std::string GetStringKey() const = 0;
};

}
