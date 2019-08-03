AddTarget(
	NAME PasswordUI
	SOURCE_DIR PasswordUI/
	SRC *.cpp *.h
	QT_USE Core Widgets
	SUBDIRS
	Interfaces
	UIController
	DEPS
	)
