cmake_minimum_required(VERSION 3.10)

AddTarget(EXECUTABLE
	NAME QJsonImplTest
	SOURCE_DIR Tests/
	SRC *.cpp *.h *.qrc
	QT_USE Core Widgets
	SUBDIRS
	QJsonImplTest
	DEPS
	gtest
	gmock_main
	JsonTools
	)

add_test(NAME QJsonImplTest COMMAND QJsonImplTest)
