set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/ICryptoHash.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IEncryptor.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IKeyProvider.h

	${CMAKE_CURRENT_LIST_DIR}/CryptoHashQt/CryptoHashQt.h
	${CMAKE_CURRENT_LIST_DIR}/CryptoHashQt/CryptoHashQt.cpp

	${CMAKE_CURRENT_LIST_DIR}/EmptyEncryptor/EmptyEncryptor.h
	${CMAKE_CURRENT_LIST_DIR}/EmptyEncryptor/EmptyEncryptor.cpp

	${CMAKE_CURRENT_LIST_DIR}/SimpleKeyProvider/SimpleKeyProvider.h
	${CMAKE_CURRENT_LIST_DIR}/SimpleKeyProvider/SimpleKeyProvider.cpp
	
	${CMAKE_CURRENT_LIST_DIR}/XOREncryptor/XOREncryptor.h
	${CMAKE_CURRENT_LIST_DIR}/XOREncryptor/XOREncryptor.cpp
	)

add_library(EncryptionLib STATIC ${SRC_LIST})

target_include_directories(EncryptionLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
