AddTarget(
	NAME PasswordUI
	SOURCE_DIR PasswordUI/
	SRC *.cpp *.h
	QT_USE Core Widgets
	UI_FILES *.ui Dialogs/*.ui Dialogs/LoginDialog/*.ui PasswordPanel/*.ui WorkspaceWidget/*.ui ToolPanel/*.ui
	SUBDIRS
	Dialogs
	Dialogs/LoginDialog
	Interfaces
	PasswordPanel
	WorkspaceWidget
	StateController
	Event
	Enums
	ToolPanel
	Models
	ModelRoles
	DEPS
	PasswordGenerator
	PasswordLogic
	QtTools
	Tools
	)
