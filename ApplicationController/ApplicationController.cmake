AddTarget(
	NAME ApplicationController
	SOURCE_DIR ApplicationController/
	SRC *.cpp *.h
	SUBDIRS
	Interfaces
	ApplicationsSettings
	ApplicationController
	Enums
	DEPS
	PasswordLogic
	PasswordGenerator
	Tools
	Encryption
	PasswordUI
	UIProtocol
	)
