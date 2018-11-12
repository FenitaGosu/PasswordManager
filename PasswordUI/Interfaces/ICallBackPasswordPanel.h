#pragma once

#include "IEventHandler.h"

class QAbstractItemModel;

namespace PasswordUI {

class ICallBackPasswordPanel : virtual public IEventHandler
{
public:
	virtual ~ICallBackPasswordPanel() = default;

	virtual QAbstractItemModel* GetPreviewDataModel() = 0;
};

}
