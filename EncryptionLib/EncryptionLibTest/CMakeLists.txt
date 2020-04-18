set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/CryptoHashQtTest.cpp
	${CMAKE_CURRENT_LIST_DIR}/XOREncryptorTest.cpp
	)

add_executable(EncryptionLibTest ${SRC_LIST})

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(EncryptionLibTest LINK_PRIVATE ${QT_MODULES_LIST})

target_link_libraries(EncryptionLibTest PRIVATE EncryptionLib)
target_link_libraries(EncryptionLibTest PRIVATE ${GTEST_BOTH_LIBRARIES})

target_include_directories(EncryptionLibTest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(EncryptionLibTest PRIVATE ${GTEST_INCLUDE_DIRS})

add_test(NAME EncryptionLibTest COMMAND EncryptionLibTest)
