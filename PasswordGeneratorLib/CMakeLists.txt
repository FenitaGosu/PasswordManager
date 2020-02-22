set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/PasswordComponents.h

	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IPasswordGenerator.h

	${CMAKE_CURRENT_LIST_DIR}/Enums/ComponentsOfPassword.h

	${CMAKE_CURRENT_LIST_DIR}/SimpleGenerator/SimpleGenerator.h
	${CMAKE_CURRENT_LIST_DIR}/SimpleGenerator/SimpleGenerator.cpp
	)

add_library(PasswordGeneratorLib STATIC ${SRC_LIST})

target_include_directories(PasswordGeneratorLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(PasswordGeneratorLib PRIVATE ToolsLib)
