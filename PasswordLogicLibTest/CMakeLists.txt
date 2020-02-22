set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/AccountsDataContainerTest.cpp
	)

add_executable(PasswordLogicLibTest ${SRC_LIST})

target_link_libraries(PasswordLogicLibTest PRIVATE PasswordLogicLib)
target_link_libraries(PasswordLogicLibTest PRIVATE ToolsLib)
target_link_libraries(PasswordLogicLibTest PRIVATE EncryptionLib)
target_link_libraries(PasswordLogicLibTest PRIVATE ${GTEST_BOTH_LIBRARIES})

target_include_directories(PasswordLogicLibTest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(PasswordLogicLibTest PRIVATE ${GTEST_INCLUDE_DIRS})

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(PasswordLogicLibTest LINK_PRIVATE ${QT_MODULES_LIST})

add_test(NAME PasswordLogicLibTest COMMAND PasswordLogicLibTest)
