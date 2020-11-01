set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/DataBaseConnectionSQLTest.cpp
	${CMAKE_CURRENT_LIST_DIR}/QuerySQLTest.cpp
	${CMAKE_CURRENT_LIST_DIR}/TransactionManagerSQLTest.cpp
	)

add_executable(DataBaseLibTest ${SRC_LIST})

target_link_libraries(DataBaseLibTest PRIVATE DataBaseLib)
target_link_libraries(DataBaseLibTest PRIVATE ${GTEST_BOTH_LIBRARIES})

target_include_directories(DataBaseLibTest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(DataBaseLibTest PRIVATE ${GTEST_INCLUDE_DIRS})

add_test(NAME DataBaseLibTest COMMAND DataBaseLibTest)
