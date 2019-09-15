cmake_minimum_required(VERSION 3.10)

AddTarget(EXECUTABLE
	NAME AllTests
	SOURCE_DIR Tests/
	SRC *.cpp *.h *.qrc
	QT_USE Core
	SUBDIRS
	JsonToolsTest
	DataBaseTest
	PasswordGeneratorTest
	EncryptionTest
	PasswordLogicTest
	ToolsTest
	UIProtocolTest
	DEPS
	gtest
	gmock_main
	JsonTools
	DataBase
	PasswordGenerator
	Encryption
	PasswordLogic
	Tools
	UIProtocol
	)

add_test(NAME AllTests COMMAND AllTests)
