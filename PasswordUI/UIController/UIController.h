#pragma once

#include "Interfaces/ICallBackPasswordPanel.h"
#include "Interfaces/ICallBackToolPanel.h"
#include "Interfaces/ICallBackCentralView.h"
#include "Interfaces/INewAccountCreator.h"

#include <QObject>
#include <QPointer>

namespace PasswordLogic {
class DataController;
}

namespace PasswordUI {

class IAccountsPanel;
class IToolsPanel;
class ICentralView;
enum class Tool;

class UIController
		: public QObject
		, public ICallBackPasswordPanel
		, public ICallBackToolPanel
		, public ICallBackCentralView
		, public INewAccountCreator
{
	Q_OBJECT

public:
	explicit UIController(QObject* parent = nullptr);
	~UIController();

	void Setup(PasswordLogic::DataController* controller, IAccountsPanel* accountsPanel, IToolsPanel* toolsPanel, ICentralView* centralView);

	/// IEventHandlers
	void HandleEvent(Event& e) override;
	void HandleEvent(Event&& e) override;

	/// ICallBackPasswordPanel
	QAbstractItemModel* GetPreviewDataModel() override;

	/// ICallBackToolPanel
	QAbstractItemModel* GetInstrumentsModel() override;

	/// ICallBackCentralView
	QAbstractItemModel* GetAccountTypeModel() override;

	/// INewAccountCreator
	void CreateNewAccount(const PasswordLogic::PreviewAccountInfo& previewInfo, const PasswordLogic::AccountInfo& accountInfo) override;

private:
	void HandleToolPaneleEvent(Tool toolId);
	void ResetUI();

	void ToViewAllAccounts();
	void ToAddAccount();
	void ToDeleteAccount();

private:
	IAccountsPanel* m_accountsPanel;
	IToolsPanel* m_toolsPanel;
	ICentralView* m_centralView;
	PasswordLogic::DataController* m_controller;

	std::unique_ptr<QAbstractItemModel> m_accountsModel;
	std::unique_ptr<QAbstractItemModel> m_toolsModel;
	std::unique_ptr<QAbstractItemModel> m_accountTypeModel;
};

}
