AddTarget(EXECUTABLE
	NAME PasswordKit
	SOURCE_DIR PasswordKit/
	SRC *.cpp *.h *.qrc
	ICON resources/icon/icon.ico
	QT_USE Core Widgets
	UI_FILES *.ui
	SUBDIRS
	Application
	Interfaces
	ApplicationSettings
	DEPS
	JsonTools
	)
