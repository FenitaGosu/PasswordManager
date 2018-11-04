#pragma once

#include "Interfaces/ICallBackPasswordPanel.h"
#include "Interfaces/ICallBackToolPanel.h"

#include <QObject>
#include <QPointer>

namespace PasswordUI {

class IPasswordPanel;
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

	void Setup(IPasswordPanel* passwordPanel, IToolPanel* toolPanel);

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

	void ToViewAllPasswords();
	void ToAddPassword();
	void ToDeletePassword();

private:
	IPasswordPanel* m_passwordPanel;
	IToolPanel* m_toolPanel;

	std::unique_ptr<QAbstractItemModel> m_passwordModel;
	std::unique_ptr<QAbstractItemModel> m_toolModel;
};

}
