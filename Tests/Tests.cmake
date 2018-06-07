cmake_minimum_required(VERSION 3.10)

AddTarget(EXECUTABLE
	NAME JsonToolsTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h *.qrc
	QT_USE Core Widgets
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
	SRC *.cpp *.h *.qrc
	QT_USE Core Widgets
	SUBDIRS
	DataBaseTest
	DEPS
	gtest
	gmock_main
	DataBase
	)

add_test(NAME DataBaseTest COMMAND DataBaseTest)