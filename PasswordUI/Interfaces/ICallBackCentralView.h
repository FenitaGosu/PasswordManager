#pragma once

#include "IEventHandler.h"

class QAbstractItemModel;

namespace PasswordUI {

class ICallBackCentralView : virtual public IEventHandler
{
public:
	virtual ~ICallBackCentralView() = default;

	virtual QAbstractItemModel* GetAccountTypeModel() = 0;
};

}
