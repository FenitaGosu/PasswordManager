AddTarget(EXECUTABLE
	NAME PasswordKit
	SOURCE_DIR PasswordKit/
	SRC *.cpp *.h
	QT_USE Core 
	SUBDIRS
	Interfaces
	Mediator
	CommandLineParserQt
	Enums
	DEPS
	ApplicationController
	PasswordLogic
	PasswordGenerator
	Tools
	Encryption
	JsonTools
	PasswordUI
	)
