AddTarget(
	NAME PasswordUI
	SOURCE_DIR PasswordUI/
	SRC *.cpp *.h
	QT_USE Core Widgets
	UI_FILES *.ui Dialogs/*.ui Dialogs/LoginDialog/*.ui
	SUBDIRS
	Dialogs
	Dialogs/LoginDialog
	DEPS
	PasswordGenerator
	PasswordLogic
	)
