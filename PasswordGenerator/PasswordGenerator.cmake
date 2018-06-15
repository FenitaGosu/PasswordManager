AddTarget(
	NAME PasswordGenerator
	SOURCE_DIR PasswordGenerator/
	SRC *.cpp *.h
	QT_USE Core
	SUBDIRS
	Interfaces
	SimpleGenerator
	Enums
	)
