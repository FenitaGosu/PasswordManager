#include <cassert>

#include <QApplication>
#include <QFile>

#include "MainWindow.h"

namespace {

const QString STYLE_PATH = ":/resources/theme/style.qss";

QString LoadStyle(const QString& file)
{
	QFile style(file);
	assert(style.open(QFile::ReadOnly));
	return style.readAll();
}

}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Q_INIT_RESOURCE(PasswordKit);
	app.setStyleSheet(app.styleSheet() + LoadStyle(STYLE_PATH));

	MainWindow w;
	w.show();

	return app.exec();
}
