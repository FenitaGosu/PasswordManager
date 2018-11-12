#pragma once

#include <QObject>

namespace PasswordLogic {
class ICredentialsInspector;
}

namespace PasswordKit {

/**
 * Mediator
 */
class Mediator : public QObject
{
	Q_OBJECT

public:
	Mediator(PasswordLogic::ICredentialsInspector* credentialsInspector, QObject* parent = nullptr);
	bool ShowLoginDialog();

public slots:
	void OnShowAbout();
	void OnShowIndependentPasswordGeneratorDialog();
	void OnShowEmbeddablePasswordGeneratorDialog(QString& pas, size_t);
	void OnShowSetMainPasswordDialog();

private:
	PasswordLogic::ICredentialsInspector* m_credentialsInspector;
};

}
