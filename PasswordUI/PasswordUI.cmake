AddTarget(
	NAME PasswordUI
	SOURCE_DIR PasswordUI/
	SRC *.cpp *.h
	QT_USE Core Widgets
	UI_FILES *.ui Dialogs/*.ui Dialogs/LoginDialog/*.ui AccountsPanel/*.ui WorkspaceWidget/*.ui ToolsPanel/*.ui
	SUBDIRS
	Dialogs
	Dialogs/LoginDialog
	Interfaces
	AccountsPanel
	WorkspaceWidget
	UIController
	Event
	Enums
	ToolsPanel
	Models
	ModelRoles
	DEPS
	PasswordGenerator
	PasswordLogic
	QtTools
	Tools
	)
