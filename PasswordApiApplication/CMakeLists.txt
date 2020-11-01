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

add_executable(PasswordApiApplication ${SRC_LIST})

target_link_libraries(PasswordApiApplication PRIVATE LoggingLib)
target_link_libraries(PasswordApiApplication PRIVATE PasswordGeneratorLib)
target_link_libraries(PasswordApiApplication PRIVATE PasswordLogicLib)
target_link_libraries(PasswordApiApplication PRIVATE PasswordLogicApiInfoLib)
target_link_libraries(PasswordApiApplication PRIVATE ToolsLib)
target_link_libraries(PasswordApiApplication PRIVATE EncryptionLib)
target_link_libraries(PasswordApiApplication PRIVATE JsonToolsLib)
target_link_libraries(PasswordApiApplication PRIVATE ApiProxyLib)

target_include_directories(PasswordApiApplication PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
