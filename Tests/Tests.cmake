cmake_minimum_required(VERSION 3.10)

AddTarget(EXECUTABLE
	NAME JsonToolsTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h *.qrc
	QT_USE Core
	SUBDIRS
	JsonToolsTest
	DEPS
	gtest
	gmock_main
	JsonTools
	)

add_test(NAME JsonToolsTest COMMAND JsonToolsTest)

AddTarget(EXECUTABLE
	NAME DataBaseTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h
	QT_USE Core
	SUBDIRS
	DataBaseTest
	DEPS
	gtest
	gmock_main
	DataBase
	)

add_test(NAME DataBaseTest COMMAND DataBaseTest)

AddTarget(EXECUTABLE
	NAME PasswordGeneratorTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h
	SUBDIRS
	PasswordGeneratorTest
	DEPS
	gtest
	gmock_main
	PasswordGenerator
	)

add_test(NAME PasswordGeneratorTest COMMAND PasswordGeneratorTest)

AddTarget(EXECUTABLE
	NAME EncryptionTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h
	SUBDIRS
	EncryptionTest
	DEPS
	gtest
	gmock_main
	Encryption
	)

add_test(NAME EncryptionTest COMMAND EncryptionTest)


AddTarget(EXECUTABLE
	NAME PasswordLogicTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h
	QT_USE Core
	SUBDIRS
	PasswordLogicTest
	DEPS
	gtest
	gmock_main
	Encryption
	PasswordLogic
	Tools
	)

add_test(NAME PasswordLogicTest COMMAND PasswordLogicTest)


AddTarget(EXECUTABLE
	NAME ToolsTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h
	SUBDIRS
	ToolsTest
	DEPS
	gtest
	gmock_main
	Tools
	)

add_test(NAME ToolsTest COMMAND ToolsTest)
