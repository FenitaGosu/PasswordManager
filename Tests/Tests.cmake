cmake_minimum_required(VERSION 3.10)

AddTarget(EXECUTABLE
	NAME ParserQJsonTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h *.qrc
	QT_USE Core Widgets
	SUBDIRS
	ParserQJsonTest
	DEPS
	gtest
	gmock_main
	JsonTools
	)

add_test(NAME ParserQJsonTest COMMAND ParserQJsonTest)

AddTarget(EXECUTABLE
	NAME DataBaseConnectionSQLTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h *.qrc
	QT_USE Core Widgets
	SUBDIRS
	DataBaseConnectionSQLTest
	DEPS
	gtest
	gmock_main
	DataBase
	)

add_test(NAME DataBaseConnectionSQLTest COMMAND DataBaseConnectionSQLTest)

AddTarget(EXECUTABLE
	NAME QuerySQLTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h *.qrc
	QT_USE Core Widgets
	SUBDIRS
	QuerySQLTest
	DEPS
	gtest
	gmock_main
	DataBase
	)

add_test(NAME QuerySQLTest COMMAND QuerySQLTest)
