cmake_minimum_required(VERSION 3.10)

project("PassworgManager")

find_package(Qt5Core)
find_package(Qt5PrintSupport)
find_package(Qt5Sql)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install/")
set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /Zi /Ob0 /Od")

if (MSVC_VERSION GREATER_EQUAL "1900")
	include(CheckCXXCompilerFlag)
	CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
	if (_cpp_latest_flag_supported)
		add_compile_options("/std:c++latest")
	endif()
endif()

include(CTest)

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

include(DownloadProject.cmake)
download_project(PROJ                googletest
				 GIT_REPOSITORY      https://github.com/google/googletest.git
				 GIT_TAG             master
				 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR})

include(addTaget.cmake)
include(PasswordUI/PasswordUI.cmake)
include(ApplicationController/ApplicationController.cmake)
include(PasswordKit/PasswordKit.cmake)
include(JsonTools/JsonTools.cmake)
include(DataBase/DataBase.cmake)
include(PasswordGenerator/PasswordGenerator.cmake)
include(Tools/Tools.cmake)
include(Encryption/Encryption.cmake)
include(PasswordLogic/PasswordLogic.cmake)
include(Tests/Tests.cmake)
include(Tests/AllTests.cmake)
