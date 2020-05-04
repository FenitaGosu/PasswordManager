set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/ILog.h

	${CMAKE_CURRENT_LIST_DIR}/LogFactory/LogFactory.h
	${CMAKE_CURRENT_LIST_DIR}/LogFactory/LogFactory.cpp

	${CMAKE_CURRENT_LIST_DIR}/EmptyLog/EmptyLog.h
	${CMAKE_CURRENT_LIST_DIR}/EmptyLog/EmptyLog.cpp

	${CMAKE_CURRENT_LIST_DIR}/StreamLog/StreamLog.h
	${CMAKE_CURRENT_LIST_DIR}/StreamLog/StreamLog.cpp

	${CMAKE_CURRENT_LIST_DIR}/Log.h
	${CMAKE_CURRENT_LIST_DIR}/Log.cpp
	)

add_library(LoggingLib STATIC ${SRC_LIST})

target_link_libraries(LoggingLib PRIVATE ToolsLib)

target_include_directories(LoggingLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
