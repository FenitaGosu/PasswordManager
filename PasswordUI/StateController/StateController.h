#pragma once

#include "Interfaces/ICallBackPasswordPanel.h"
#include "Interfaces/ICallBackToolPanel.h"

#include <QObject>
#include <QPointer>

namespace PasswordUI {

class IAccountsPanel;
class IToolPanel;
enum class Tool;

class StateController
		: public QObject
		, public ICallBackPasswordPanel
		, public ICallBackToolPanel
{
	Q_OBJECT

public:
	explicit StateController(QObject* parent = nullptr);
	~StateController();

	void Setup(IAccountsPanel* passwordPanel, IToolPanel* toolPanel);

	/// IEventHandler
	void HandleEvent(Event& e) override;
	void HandleEvent(Event&& e) override;

	/// ICallBackPasswordPanel
	QAbstractItemModel* GetShortDataModel() override;

	/// ICallBackToolPanel
	QAbstractItemModel* GetInstrumentsModel() override;

private:
	void HandleToolPaneleEvent(Tool toolId);
	void ResetUI();

	void ToViewAllAccounts();
	void ToAddAccount();
	void ToDeleteAccount();

private:
	IAccountsPanel* m_passwordPanel;
	IToolPanel* m_toolPanel;

	std::unique_ptr<QAbstractItemModel> m_passwordModel;
	std::unique_ptr<QAbstractItemModel> m_toolModel;
};

}
