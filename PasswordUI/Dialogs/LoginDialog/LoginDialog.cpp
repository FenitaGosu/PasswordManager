#include <cassert>

#include "PasswordLogic/Interfaces/ICredentialsInspector.h"

#include "Interfaces/IObjectsConnector.h"

#include "LoginControllerFirstStartMode.h"
#include "LoginControllerLoginMode.h"
#include "LoginControllerSetPasswordMode.h"

#include "LoginDialog.h"
#include "ui_LoginDialog.h"

using namespace PasswordUI;
using namespace PasswordKit;

LoginDialog::LoginDialog(Mode mode, PasswordLogic::ICredentialsInspector* const credentialsInspector, QWidget* parent)
	: QDialog(parent)
	, m_ui(new Ui::LoginDialog())
	, m_controller(CreateController(mode, this, credentialsInspector))
{
	m_ui->setupUi(this);
	setWindowFlags (windowFlags() | Qt::FramelessWindowHint);
	m_controller->Setup();

	ObjectsConnector::RegisterEmitter(IObjectsConnector::GENERATE_PASSWORD, this, SIGNAL(generatePassword(QString&, size_t)));
}

bool LoginDialog::Exec()
{
	while (true)
	{
		m_controller->Setup();

		m_needGeneratePassword = false;

		bool returnValue = static_cast<bool>(exec());

		if(!m_needGeneratePassword)
			return returnValue;

		QString newPassword;
		emit generatePassword(newPassword, ILoginDialog::MIN_PAS_LENGHT);
		m_controller->SetDefaultNewPassword(newPassword);
	}
}

void LoginDialog::Reject()
{
	emit reject();
}

void LoginDialog::Accept()
{
	emit accept();
}

void LoginDialog::Generate()
{
	m_needGeneratePassword = true;
	Reject();
}

Ui::LoginDialog* LoginDialog::GetUi() const noexcept
{
	return m_ui.data();
}

LoginDialog::~LoginDialog() = default;

std::unique_ptr<BaseLoginController> LoginDialog::CreateController(LoginDialog::Mode mode, ILoginDialog* loginDialog, PasswordLogic::ICredentialsInspector* credentialsInspector) const
{
	switch (mode)
	{
		case Mode::Login:
			return std::make_unique<LoginControllerLoginMode>(credentialsInspector, loginDialog);
		case Mode::SetPassword:
			return std::make_unique<LoginControllerSetPasswordMode>(credentialsInspector, loginDialog);
		case Mode::FisrtStart:
			return std::make_unique<LoginControllerFirstStartMode>(credentialsInspector, loginDialog);
	}

	assert(true && "Logic invalid");
	return nullptr;
}
