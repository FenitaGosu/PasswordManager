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

public slots:
	void OnAboutClicked();

};

}
