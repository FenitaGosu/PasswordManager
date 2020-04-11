set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IApplicationSettings.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IDataStream.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IApiProxy.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/ICommandLineParser.h

	${CMAKE_CURRENT_LIST_DIR}/ApplicationController/ApplicationController.h
	${CMAKE_CURRENT_LIST_DIR}/ApplicationController/ApplicationController.cpp
	)

add_library(ApplicationControllerLib STATIC ${SRC_LIST})

target_include_directories(ApplicationControllerLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
