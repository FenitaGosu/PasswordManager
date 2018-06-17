AddTarget(
	NAME PasswordGenerator
	SOURCE_DIR PasswordGenerator/
	SRC *.cpp *.h
	QT_USE Core
	DEPS
	Tools
	SUBDIRS
	Interfaces
	SimpleGenerator
	Enums
	)
