set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/ReaderQJsonTest.cpp
	${CMAKE_CURRENT_LIST_DIR}/WriterQJsonTest.cpp
	${CMAKE_CURRENT_LIST_DIR}/resources.qrc
	)

add_executable(JsonToolsLibTest ${SRC_LIST})

set(QT_MODULES_LIST
	Core
	)

set_target_properties(JsonToolsLibTest PROPERTIES AUTOMOC ON AUTORCC ON)
qt5_use_modules(JsonToolsLibTest LINK_PRIVATE ${QT_MODULES_LIST})

target_link_libraries(JsonToolsLibTest PRIVATE JsonToolsLib)
target_link_libraries(JsonToolsLibTest PRIVATE ${GTEST_BOTH_LIBRARIES})

target_include_directories(JsonToolsLibTest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(JsonToolsLibTest PRIVATE ${GTEST_INCLUDE_DIRS})

add_test(NAME JsonToolsLibTest COMMAND JsonToolsLibTest)
