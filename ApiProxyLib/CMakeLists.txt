set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IApiProxy.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IApiProxyMethod.h

	${CMAKE_CURRENT_LIST_DIR}/ApiProxy/ApiProxy.h
	${CMAKE_CURRENT_LIST_DIR}/ApiProxy/ApiProxy.cpp

	${CMAKE_CURRENT_LIST_DIR}/ApiProxyMethod/ApiProxyMethod.h
	)

add_library(ApiProxyLib STATIC ${SRC_LIST})

target_include_directories(ApiProxyLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(ApiProxyLib PRIVATE ToolsLib)
