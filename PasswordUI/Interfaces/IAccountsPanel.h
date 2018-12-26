#pragma once

class QString;

namespace PasswordUI {

class IAccountsPanel
{
public:
	virtual ~IAccountsPanel() = default;

	virtual void Hide() = 0;
	virtual void Show() = 0;
	virtual void Update() = 0;
	virtual void SelectItem(const QString& id) = 0;
};

}
