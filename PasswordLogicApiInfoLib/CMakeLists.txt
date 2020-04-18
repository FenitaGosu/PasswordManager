set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/ApiParameters.h
	${CMAKE_CURRENT_LIST_DIR}/ApiParameters.cpp
	)

add_library(PasswordLogicApiInfoLib STATIC ${SRC_LIST})

target_include_directories(PasswordLogicApiInfoLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)


target_link_libraries(PasswordLogicApiInfoLib PRIVATE ToolsLib)
