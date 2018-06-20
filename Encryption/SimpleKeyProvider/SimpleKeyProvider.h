#pragma once

#include "Interfaces/IKeyProvider.h"

namespace Encryption {

class SimpleKeyProvider : public IKeyProvider
{
public:
	SimpleKeyProvider(const std::string& str);

	std::string GetStringKey() const override;

private:
	std::string m_key;
};

}
