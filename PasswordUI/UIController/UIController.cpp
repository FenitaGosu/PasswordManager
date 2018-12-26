#include <QAbstractItemModel>

#include "PasswordLogic/AccountInfo/PreviewAccountInfo.h"

#include "PasswordLogic/DataController/DataController.h"

#include "Event/Event.h"

#include "Enums/Tool.h"
#include "Enums/AccontType.h"

#include "Interfaces/IAccountsPanel.h"
#include "Interfaces/IToolsPanel.h"
#include "Interfaces/ICentralView.h"

#include "Models/ModelTool.h"
#include "Models/ModelAccount.h"
#include "Models/ModelAccountType.h"

#include "SystemConstants.h"
#include "UIController.h"

using namespace PasswordUI;

UIController::UIController(QObject* parent)
	: QObject(parent)
{
}

UIController::~UIController() = default;

void UIController::Setup(PasswordLogic::DataController *controller, IAccountsPanel* accountsPanel, IToolsPanel* toolsPanel, ICentralView* centralView)
{
	m_controller = controller;
	m_accountsPanel = accountsPanel;
	m_toolsPanel = toolsPanel;
	m_centralView = centralView;
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

QAbstractItemModel* UIController::GetAccountTypeModel()
{
	std::vector<PasswordLogic::AccountType> types =
	{
		PasswordLogic::AccountType::Simple,
		PasswordLogic::AccountType::Mail,
		PasswordLogic::AccountType::Game
	};

	m_accountTypeModel = std::make_unique<ModelAccountType>(std::move(types));
	return m_accountTypeModel.get();
}

void UIController::CreateNewAccount(const PasswordLogic::PreviewAccountInfo& previewInfo, const PasswordLogic::AccountInfo& accountInfo)
{
	m_controller->AddNewAccount(previewInfo, accountInfo);

	m_accountsPanel->Update();
	m_accountsPanel->SelectItem(previewInfo.GetId());

	HandleEvent(Event(EventType::ToolsPanel, SystemConstants::ACTIVATE_TOOL, static_cast<int>(Tool::Accounts)));
	HandleEvent(Event(EventType::AccountsPanel, SystemConstants::ACCOUNT_CLICKED, previewInfo.GetId().toStdString()));
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
	m_centralView->ActivateMode(ICentralView::Mode::ViewAccount);
}

void UIController::ToAddAccount()
{
	m_centralView->ActivateMode(ICentralView::Mode::AddNewAccount);
}

void UIController::ToDeleteAccount()
{
	m_accountsPanel->Show();
	m_centralView->ActivateMode(ICentralView::Mode::ViewAccount);
}
