#pragma once
#include <QObject>

namespace PasswordLogic {
class ICredentialsInspector;
}

namespace PasswordUI {

class ILoginDialog;

class BaseLoginController : public QObject
{
public:
	BaseLoginController( PasswordLogic::ICredentialsInspector* const inspector, ILoginDialog* const dialog);

	void SetDefaultNewPassword(const QString& password);

	virtual ~BaseLoginController() = default;
	virtual void Setup() = 0;

private:
	virtual void OnOkClicked() {}
	virtual void OnExitClicked() {}
	virtual void OnSaveClicked() {}
	virtual void OnCancelClicked() {}
	virtual void OnNewPasswordClicked() {}

protected:
	PasswordLogic::ICredentialsInspector* const m_inspector;
	ILoginDialog* const m_dialog;
};

}
