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
	ApplicationsSettings
	ApplicationController
	DEPS	
	PasswordLogic
	Tools
	)
