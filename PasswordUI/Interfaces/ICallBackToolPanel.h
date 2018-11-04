#pragma once

#include "IEventHandler.h"

class QAbstractItemModel;

namespace PasswordUI {

class ICallBackToolPanel : virtual public IEventHandler
{
public:
	virtual ~ICallBackToolPanel() = default;

	virtual QAbstractItemModel* GetInstrumentsModel() = 0;
};

}
