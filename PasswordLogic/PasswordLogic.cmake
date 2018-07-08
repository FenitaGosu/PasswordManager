AddTarget(
	NAME PasswordLogic
	SOURCE_DIR PasswordLogic/
	SRC *.cpp *.h *.qrc
	QT_USE Core
	SUBDIRS
	Interfaces
	CredentialsInspector
	)
