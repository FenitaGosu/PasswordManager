set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IApplicationSettings.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IDataStream.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/ICommandLineParser.h

	${CMAKE_CURRENT_LIST_DIR}/ApplicationController/ApplicationController.h
	${CMAKE_CURRENT_LIST_DIR}/ApplicationController/ApplicationController.cpp

	${CMAKE_CURRENT_LIST_DIR}/CommandLineParserQt/CommandLineParserQt.h
	${CMAKE_CURRENT_LIST_DIR}/CommandLineParserQt/CommandLineParserQt.cpp

	${CMAKE_CURRENT_LIST_DIR}/Mediator/Mediator.h
	${CMAKE_CURRENT_LIST_DIR}/Mediator/Mediator.cpp

	${CMAKE_CURRENT_LIST_DIR}/Streams/StandartStreamsWrapper.h
	${CMAKE_CURRENT_LIST_DIR}/Streams/StandartStreamsWrapper.cpp

	${CMAKE_CURRENT_LIST_DIR}/ApplicationSettings/ApplicationSettings.h
	${CMAKE_CURRENT_LIST_DIR}/ApplicationSettings/ApplicationSettings.cpp

	${CMAKE_CURRENT_LIST_DIR}/ApiProxyMethodExecuter/ApiProxyMethodExecuter.h
	${CMAKE_CURRENT_LIST_DIR}/ApiProxyMethodExecuter/ApiProxyMethodExecuter.cpp

	${CMAKE_CURRENT_LIST_DIR}/main.cpp
	)

add_executable(PasswordKit ${SRC_LIST})

target_link_libraries(PasswordKit PRIVATE PasswordGeneratorLib)
target_link_libraries(PasswordKit PRIVATE PasswordLogicLib)
target_link_libraries(PasswordKit PRIVATE PasswordLogicApiInfoLib)
target_link_libraries(PasswordKit PRIVATE ToolsLib)
target_link_libraries(PasswordKit PRIVATE EncryptionLib)
target_link_libraries(PasswordKit PRIVATE JsonToolsLib)
target_link_libraries(PasswordKit PRIVATE ApiProxyLib)

target_include_directories(PasswordKit PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(PasswordKit LINK_PRIVATE ${QT_MODULES_LIST})