find_path(BOOST_PROPERTY_TREE_INCLUDE_DIRS "boost/property_tree/ptree.hpp" "boost/property_tree/json_parser.hpp")

set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IReaderJson.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IWriterJson.h

	${CMAKE_CURRENT_LIST_DIR}/ReaderJson/ReaderJson.h
	${CMAKE_CURRENT_LIST_DIR}/ReaderJson/ReaderJson.cpp

	${CMAKE_CURRENT_LIST_DIR}/WriterJson/WriterJson.h
	${CMAKE_CURRENT_LIST_DIR}/WriterJson/WriterJson.cpp

	${CMAKE_CURRENT_LIST_DIR}/JsonSerialize/JsonSerializer.h
	${CMAKE_CURRENT_LIST_DIR}/JsonSerialize/JsonDeserializer.h
	${CMAKE_CURRENT_LIST_DIR}/JsonSerialize/JsonSerializeFactory.h

	${CMAKE_CURRENT_LIST_DIR}/JsonSerialize/JsonSerializer.cpp
	${CMAKE_CURRENT_LIST_DIR}/JsonSerialize/JsonDeserializer.cpp
	${CMAKE_CURRENT_LIST_DIR}/JsonSerialize/JsonSerializeFactory.cpp
	)

add_library(JsonToolsLib STATIC ${SRC_LIST})

target_include_directories(JsonToolsLib PRIVATE ${BOOST_PROPERTY_TREE_INCLUDE_DIRS})

target_include_directories(JsonToolsLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(JsonToolsLib PRIVATE ToolsLib)
