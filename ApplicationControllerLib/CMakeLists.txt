set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IApplicationSettings.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IDataStream.h

	${CMAKE_CURRENT_LIST_DIR}/ApplicationController/ApplicationController.h
	${CMAKE_CURRENT_LIST_DIR}/ApplicationController/ApplicationController.cpp

	${CMAKE_CURRENT_LIST_DIR}/ApplicationSettings/ApplicationSettings.h
	${CMAKE_CURRENT_LIST_DIR}/ApplicationSettings/ApplicationSettings.cpp
	)

add_library(ApplicationControllerLib STATIC ${SRC_LIST})

target_include_directories(ApplicationControllerLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(ApplicationControllerLib PRIVATE PasswordLogicLib)
target_link_libraries(ApplicationControllerLib PRIVATE ToolsLib)
target_link_libraries(ApplicationControllerLib PRIVATE EncryptionLib)
target_link_libraries(ApplicationControllerLib PRIVATE JsonToolsLib)
