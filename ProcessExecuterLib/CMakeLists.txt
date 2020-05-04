set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IProcessExecuter.h

	${CMAKE_CURRENT_LIST_DIR}/QtProcessExecuter/QtProcessExecuter.h
	${CMAKE_CURRENT_LIST_DIR}/QtProcessExecuter/QtProcessExecuter.cpp
	)

add_library(ProcessExecuterLib STATIC ${SRC_LIST})

target_include_directories(ProcessExecuterLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(ProcessExecuterLib PRIVATE ToolsLib)

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(ProcessExecuterLib LINK_PRIVATE ${QT_MODULES_LIST})
