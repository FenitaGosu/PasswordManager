#pragma once

class QVariant;

namespace PasswordLogic {

class IDataContainer
{
public:
	virtual ~IDataContainer() = default;

	virtual void AddData(QVariant&& data) = 0;
	virtual QVariant GetData() = 0;
};

}
