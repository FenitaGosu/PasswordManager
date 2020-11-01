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
	${CMAKE_CURRENT_LIST_DIR}/Serialize/ISerializeFactory.h

	${CMAKE_CURRENT_LIST_DIR}/CommandLineParser/ICommandLineParser.h
	${CMAKE_CURRENT_LIST_DIR}/CommandLineParser/CommandLineParser.h
	${CMAKE_CURRENT_LIST_DIR}/CommandLineParser/CommandLineParser.cpp
	)

add_library(ToolsLib STATIC ${SRC_LIST})

find_package(Boost REQUIRED COMPONENTS program_options)

target_link_libraries(ToolsLib PRIVATE Boost::program_options)

target_include_directories(ToolsLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
