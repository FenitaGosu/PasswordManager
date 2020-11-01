set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/ReaderJsonTest.cpp
	${CMAKE_CURRENT_LIST_DIR}/WriterJsonTest.cpp
	)

add_executable(JsonToolsLibTest ${SRC_LIST})

target_link_libraries(JsonToolsLibTest PRIVATE JsonToolsLib)
target_link_libraries(JsonToolsLibTest PRIVATE ${GTEST_BOTH_LIBRARIES})

target_include_directories(JsonToolsLibTest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(JsonToolsLibTest PRIVATE ${GTEST_INCLUDE_DIRS})

add_test(NAME JsonToolsLibTest COMMAND JsonToolsLibTest)

file(GLOB files_test "${CMAKE_CURRENT_LIST_DIR}/tests/*json")

foreach(file ${files_test})
    get_filename_component(name "${file}" NAME)
    configure_file("${CMAKE_CURRENT_LIST_DIR}/tests/${name}" "${CMAKE_CURRENT_BINARY_DIR}/${name}" COPYONLY)
endforeach()
