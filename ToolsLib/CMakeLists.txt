set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Random/RandomIntGenerator.h
	${CMAKE_CURRENT_LIST_DIR}/Random/RandomIntGenerator.cpp

	${CMAKE_CURRENT_LIST_DIR}/Same/Same.h
	${CMAKE_CURRENT_LIST_DIR}/Same/Same.cpp

	${CMAKE_CURRENT_LIST_DIR}/StreamWrapper/StreamWrapper.h
	${CMAKE_CURRENT_LIST_DIR}/StreamWrapper/StreamWrapper.cpp

	${CMAKE_CURRENT_LIST_DIR}/StringFormat/StringFormat.h

	${CMAKE_CURRENT_LIST_DIR}/Serialize/ISerializer.h
	${CMAKE_CURRENT_LIST_DIR}/Serialize/IDeserializer.h
	${CMAKE_CURRENT_LIST_DIR}/Serialize/IDeserializer.h
	)

add_library(ToolsLib STATIC ${SRC_LIST})

target_include_directories(ToolsLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(ToolsLib LINK_PRIVATE ${QT_MODULES_LIST})
