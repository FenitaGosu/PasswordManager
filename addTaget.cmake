macro(PrefixSuffix ListName Prefix Suffix)
	set(__tmp)
	foreach(val ${${ListName}})
		list(APPEND __tmp "${Prefix}${val}${Suffix}")
	endforeach()
	set(${ListName} ${__tmp})
endmacro()

function(AddTarget)
	set(__options
		EXECUTABLE
		)
	set(__oneVal
		NAME
		SOURCE_DIR
		ICON
		)
	set(__multiVal
		SRC
		INCLUDES
		DEFINES
		QT_USE
		SUBDIRS
		UI_FILES
		DEPS
		)
	cmake_parse_arguments(ARG "${__options}" "${__oneVal}" "${__multiVal}" ${ARGN})

	set(name ${ARG_NAME})

	set(sourceMasks ${ARG_SRC})
	foreach(subDir ${ARG_SUBDIRS})
		foreach(mask ${ARG_SRC})
			list(APPEND sourceMasks ${subDir}/${mask})
		endforeach()
	endforeach()

	PrefixSuffix(sourceMasks "${ARG_SOURCE_DIR}" "")

	file(GLOB sources ${sourceMasks})

	if (ARG_UI_FILES)
		PrefixSuffix(ARG_UI_FILES "${ARG_SOURCE_DIR}" "")
		set(CMAKE_CURRENT_BINARY_DIR_BCK ${CMAKE_CURRENT_BINARY_DIR})
		set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/${name})
		file(GLOB uiFiles ${ARG_UI_FILES})
		qt5_wrap_ui(uiFilesOut ${uiFiles})
		set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR_BCK})
		list(APPEND sources ${uiFiles})
	endif()

	if (ARG_ICON)
		set(APP_ICON ${CMAKE_CURRENT_SOURCE_DIR}/${ARG_SOURCE_DIR}${ARG_ICON})
		set(appRc ${CMAKE_CURRENT_BINARY_DIR}/${name}_icon.rc)
		configure_file(resource_template.rc.in ${appRc})
		list(APPEND sources ${APP_ICON} ${appRc})
	endif()

	if (ARG_EXECUTABLE)
		add_executable(${name} ${sources})
	else()
		add_library(${name} STATIC ${sources})
	endif()

	if (ARG_QT_USE)
		qt5_use_modules(${name} LINK_PRIVATE ${ARG_QT_USE})
		set_target_properties(${name} PROPERTIES AUTOMOC ON AUTORCC ON)
	endif()

	list(APPEND ARG_INCLUDES ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/${name})
	target_include_directories(${name} PUBLIC ${ARG_SOURCE_DIR})
	foreach (inc ${ARG_INCLUDES})
		target_include_directories(${name} PRIVATE ${inc})
	endforeach()

	foreach (dep ${ARG_DEPS})
		target_link_libraries(${name} PRIVATE ${dep})
	endforeach()

	if (ARG_EXECUTABLE)
		install(TARGETS ${name} COMPONENT ${name} RUNTIME DESTINATION ${name})
	endif()
endfunction()
