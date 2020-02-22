set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/SimpleGeneratorTest.cpp
	)

add_executable(PasswordGeneratorLibTest ${SRC_LIST})

target_link_libraries(PasswordGeneratorLibTest PRIVATE PasswordGeneratorLib)
target_link_libraries(PasswordGeneratorLibTest PRIVATE ${GTEST_BOTH_LIBRARIES})

target_include_directories(PasswordGeneratorLibTest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(PasswordGeneratorLibTest PRIVATE ${GTEST_INCLUDE_DIRS})

add_test(NAME PasswordGeneratorLibTest COMMAND PasswordGeneratorLibTest)
