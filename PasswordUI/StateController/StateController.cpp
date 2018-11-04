#include <QAbstractItemModel>

#include "Event/Event.h"

#include "Enums/Tool.h"

#include "Interfaces/IAccountsPanel.h"
#include "Interfaces/IToolPanel.h"

#include "Models/ModelTool.h"
#include "Models/ModelPassword.h"

#include "SystemConstants.h"
#include "StateController.h"

using namespace PasswordUI;

StateController::StateController(QObject* parent)
	: QObject(parent)
{
}

StateController::~StateController() = default;

void StateController::Setup(IAccountsPanel* passwordPanel, IToolPanel* toolPanel)
{
	m_passwordPanel = passwordPanel;
	m_toolPanel = toolPanel;
}

void StateController::HandleEvent(Event&)
{
	assert(false);
}

void StateController::HandleEvent(Event&& e)
{
	switch (e.GetType())
	{
		case EventType::ToolPanel:
			HandleToolPaneleEvent(static_cast<Tool>(e.GetInt(SystemConstants::ACTIVATE_TOOL).value_or(-1)));
		break;

		case EventType::PasswordPanel:
			assert(false);
		break;
	}
}

QAbstractItemModel* StateController::GetShortDataModel()
{
	m_passwordModel = std::make_unique<ModelPassword>();
	return m_passwordModel.get();
}

QAbstractItemModel* StateController::GetInstrumentsModel()
{
	std::vector<Tool> tools =
	{
		Tool::Accounts,
		Tool::AddAccount,
		Tool::DeleteAccount
	};

	m_toolModel = std::make_unique<ModelTool>(std::move(tools));
	return m_toolModel.get();
}

void StateController::HandleToolPaneleEvent(Tool toolId)
{
	m_toolPanel->ActivateTool(toolId);

	ResetUI();

	switch (toolId)
	{
		case Tool::Accounts:
			ToViewAllAccounts();
		break;

		case Tool::AddAccount:
			ToAddAccount();
		break;

		case Tool::DeleteAccount:
			ToDeleteAccount();
		break;

		default:
		break;
	}
}

void StateController::ResetUI()
{
	m_passwordPanel->Hide();
}

void StateController::ToViewAllAccounts()
{
	m_passwordPanel->Show();
}

void StateController::ToAddAccount()
{
}

void StateController::ToDeleteAccount()
{
	m_passwordPanel->Show();
}
