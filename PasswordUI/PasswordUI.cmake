AddTarget(
	NAME PasswordUI
	SOURCE_DIR PasswordUI/
	SRC *.cpp *.h
	QT_USE Core Widgets
	UI_FILES *.ui Dialogs/*.ui Dialogs/LoginDialog/*.ui AccountsPanel/*.ui WorkspaceWidget/*.ui ToolPanel/*.ui
	SUBDIRS
	Dialogs
	Dialogs/LoginDialog
	Interfaces
	AccountsPanel
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
