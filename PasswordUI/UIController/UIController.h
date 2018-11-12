#pragma once

#include "Interfaces/ICallBackPasswordPanel.h"
#include "Interfaces/ICallBackToolPanel.h"

#include <QObject>
#include <QPointer>

namespace PasswordLogic {
class DataController;
}

namespace PasswordUI {

class IAccountsPanel;
class IToolsPanel;
enum class Tool;

class UIController
		: public QObject
		, public ICallBackPasswordPanel
		, public ICallBackToolPanel
{
	Q_OBJECT

public:
	explicit UIController(QObject* parent = nullptr);
	~UIController();

	void Setup(PasswordLogic::DataController* controller, IAccountsPanel* accountsPanel, IToolsPanel* toolsPanel);

	/// IEventHandlers
	void HandleEvent(Event& e) override;
	void HandleEvent(Event&& e) override;

	/// ICallBackPasswordPanel
	QAbstractItemModel* GetPreviewDataModel() override;

	/// ICallBackToolPanel
	QAbstractItemModel* GetInstrumentsModel() override;

private:
	void HandleToolPaneleEvent(Tool toolId);
	void ResetUI();

	void ToViewAllAccounts();
	void ToAddAccount();
	void ToDeleteAccount();

private:
	IAccountsPanel* m_accountsPanel;
	IToolsPanel* m_toolsPanel;
	PasswordLogic::DataController* m_controller;

	std::unique_ptr<QAbstractItemModel> m_accountsModel;
	std::unique_ptr<QAbstractItemModel> m_toolsModel;
};

}
