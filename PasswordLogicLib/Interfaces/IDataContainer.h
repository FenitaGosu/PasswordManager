#pragma once

#include "PasswordLogicLib/SameContainers.h"

namespace PasswordLogic {

class IDataContainer
{
public:
	virtual ~IDataContainer() = default;

	virtual void AddDataList(DataList&& data) = 0;
	virtual const DataList& GetDataList() const = 0;

	virtual void AddData(Data&& data) = 0;
	virtual const Data& GetData(size_t i = 0) const = 0;
};

}
