set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/SameTest.cpp
	${CMAKE_CURRENT_LIST_DIR}/StreamWrapperTest.cpp
	${CMAKE_CURRENT_LIST_DIR}/StringFormat.cpp
	)

add_executable(ToolsLibTest ${SRC_LIST})

target_link_libraries(ToolsLibTest PRIVATE ToolsLib)
target_link_libraries(ToolsLibTest PRIVATE ${GTEST_BOTH_LIBRARIES})

target_include_directories(ToolsLibTest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(ToolsLibTest PRIVATE ${GTEST_INCLUDE_DIRS})

add_test(NAME ToolsLibTest COMMAND ToolsLibTest)
