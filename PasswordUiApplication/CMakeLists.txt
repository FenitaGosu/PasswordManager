set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/main.cpp

	${CMAKE_CURRENT_LIST_DIR}/MainWindow/MainWindow.h
	${CMAKE_CURRENT_LIST_DIR}/MainWindow/MainWindow.cpp
	)

add_executable(PasswordUiApplication WIN32 ${SRC_LIST})

target_link_libraries(PasswordUiApplication PRIVATE LoggingLib)

target_include_directories(PasswordUiApplication PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

set(QT_MODULES_LIST
	Core
	Widgets
	)

qt5_use_modules(PasswordUiApplication LINK_PRIVATE ${QT_MODULES_LIST})
set_target_properties(PasswordUiApplication PROPERTIES AUTOMOC ON AUTORCC ON)
