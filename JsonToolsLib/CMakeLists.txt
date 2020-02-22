set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IReaderJson.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IWriterJson.h

	${CMAKE_CURRENT_LIST_DIR}/JsonFactory/JsonFactory.h
	${CMAKE_CURRENT_LIST_DIR}/JsonFactory/JsonFactory.cpp

	${CMAKE_CURRENT_LIST_DIR}/ReaderQJson/ReaderQJson.h
	${CMAKE_CURRENT_LIST_DIR}/ReaderQJson/ReaderQJson.cpp

	${CMAKE_CURRENT_LIST_DIR}/WriterQJson/WriterQJson.h
	${CMAKE_CURRENT_LIST_DIR}/WriterQJson/WriterQJson.cpp
	)

add_library(JsonToolsLib STATIC ${SRC_LIST})

target_include_directories(JsonToolsLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(JsonToolsLib PRIVATE ToolsLib)

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(JsonToolsLib LINK_PRIVATE ${QT_MODULES_LIST})
