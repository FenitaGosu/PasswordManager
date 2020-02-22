set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IApplicationSettings.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/ICommandLineParser.h

	${CMAKE_CURRENT_LIST_DIR}/CommandLineParserQt/CommandLineParserQt.h
	${CMAKE_CURRENT_LIST_DIR}/CommandLineParserQt/CommandLineParserQt.cpp

	${CMAKE_CURRENT_LIST_DIR}/Mediator/Mediator.h
	${CMAKE_CURRENT_LIST_DIR}/Mediator/Mediator.cpp

	${CMAKE_CURRENT_LIST_DIR}/main.cpp
	)

add_executable(PasswordKit ${SRC_LIST})

target_link_libraries(PasswordKit PRIVATE ApplicationControllerLib)
target_link_libraries(PasswordKit PRIVATE PasswordGeneratorLib)
target_link_libraries(PasswordKit PRIVATE PasswordLogicLib)
target_link_libraries(PasswordKit PRIVATE ToolsLib)
target_link_libraries(PasswordKit PRIVATE EncryptionLib)
target_link_libraries(PasswordKit PRIVATE JsonToolsLib)

target_include_directories(PasswordKit PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(PasswordKit LINK_PRIVATE ${QT_MODULES_LIST})