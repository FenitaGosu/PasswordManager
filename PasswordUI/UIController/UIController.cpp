#include <QAbstractItemModel>

#include "PasswordLogic/AccountInfo/PreviewAccoutInfo.h"

#include "PasswordLogic/DataController/DataController.h"

#include "Event/Event.h"

#include "Enums/Tool.h"

#include "Interfaces/IAccountsPanel.h"
#include "Interfaces/IToolsPanel.h"

#include "Models/ModelTool.h"
#include "Models/ModelAccount.h"

#include "SystemConstants.h"
#include "UIController.h"

using namespace PasswordUI;

UIController::UIController(QObject* parent)
	: QObject(parent)
{
}

UIController::~UIController() = default;

void UIController::Setup(PasswordLogic::DataController *controller, IAccountsPanel* accountsPanel, IToolsPanel* toolsPanel)
{
	m_controller = controller;
	m_accountsPanel = accountsPanel;
	m_toolsPanel = toolsPanel;
}

void UIController::HandleEvent(Event&)
{
	assert(false);
}

void UIController::HandleEvent(Event&& e)
{
	switch (e.GetType())
	{
		case EventType::ToolsPanel:
			HandleToolPaneleEvent(static_cast<Tool>(e.GetInt(SystemConstants::ACTIVATE_TOOL).value_or(-1)));
		break;

		case EventType::AccountsPanel:
			/// @todo e.GetString(SystemConstants::ACCOUNT_CLICKED).value_or("INVALID_ID");
		break;
	}
}

QAbstractItemModel* UIController::GetPreviewDataModel()
{
	m_accountsModel = std::make_unique<ModelAccount>(m_controller->GetPreviewAccountsInfo());
	return m_accountsModel.get();
}

QAbstractItemModel* UIController::GetInstrumentsModel()
{
	std::vector<Tool> tools =
	{
		Tool::Accounts,
		Tool::AddAccount,
		Tool::DeleteAccount
	};

	m_toolsModel = std::make_unique<ModelTool>(std::move(tools));
	return m_toolsModel.get();
}

void UIController::HandleToolPaneleEvent(Tool toolId)
{
	m_toolsPanel->ActivateTool(toolId);

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

void UIController::ResetUI()
{
	m_accountsPanel->Hide();
}

void UIController::ToViewAllAccounts()
{
	m_accountsPanel->Show();
}

void UIController::ToAddAccount()
{
}

void UIController::ToDeleteAccount()
{
	m_accountsPanel->Show();
}
