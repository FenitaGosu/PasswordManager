#pragma once

#include <QObject>

namespace PasswordKit {

/**
 * Mediator
 */
class Mediator : public QObject
{
	Q_OBJECT

public:
	Mediator(QObject* parent = nullptr);
	bool ShowLoginDialog();

public slots:
	void OnShowAbout();
	void OnShowIndependentPasswordGeneratorDialog();
	void OnShowEmbeddablePasswordGeneratorDialog(QString& pas);
};

}
