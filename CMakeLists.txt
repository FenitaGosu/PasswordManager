cmake_minimum_required(VERSION 3.15)

project("PassworgManager")

set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /Zi /Ob0 /Od")

add_compile_options("/std:c++17")

enable_testing()

find_package(Qt5Core REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(GTest REQUIRED)

#libs
add_subdirectory(DataBaseLib)
add_subdirectory(EncryptionLib)
add_subdirectory(ToolsLib)
add_subdirectory(JsonToolsLib)
add_subdirectory(LoggingLib)

add_subdirectory(PasswordGeneratorLib)
add_subdirectory(PasswordLogicLib)
add_subdirectory(PasswordLogicApiInfoLib)
add_subdirectory(ApiProxyLib)
add_subdirectory(ProcessExecuterLib)

#tests
add_subdirectory(DataBaseLibTest)
add_subdirectory(EncryptionLibTest)
add_subdirectory(ToolsLibTest)
add_subdirectory(JsonToolsLibTest)
add_subdirectory(PasswordGeneratorLibTest)
add_subdirectory(PasswordLogicLibTest)

#bin
add_subdirectory(PasswordApiApplication)
add_subdirectory(PasswordUiApplication)