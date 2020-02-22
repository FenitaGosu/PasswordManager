set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/ICredentialsInspector.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/ICredentialSource.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IDataContainer.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IDataController.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IDataSource.h

	${CMAKE_CURRENT_LIST_DIR}/AccountInfo/AccountInfo.h
	${CMAKE_CURRENT_LIST_DIR}/AccountInfo/AccountInfo.cpp
	${CMAKE_CURRENT_LIST_DIR}/AccountInfo/AccountInfoDec.h

	${CMAKE_CURRENT_LIST_DIR}/CredentialsInspector/CredentialsInspector.h
	${CMAKE_CURRENT_LIST_DIR}/CredentialsInspector/CredentialsInspector.cpp

	${CMAKE_CURRENT_LIST_DIR}/DataContainer/AccountsDataContainer.h
	${CMAKE_CURRENT_LIST_DIR}/DataContainer/AccountsDataContainer.cpp
	${CMAKE_CURRENT_LIST_DIR}/DataContainer/EncryptedDataContainer.h
	${CMAKE_CURRENT_LIST_DIR}/DataContainer/EncryptedDataContainer.cpp
	
	${CMAKE_CURRENT_LIST_DIR}/DataController/DataController.h
	${CMAKE_CURRENT_LIST_DIR}/DataController/DataController.cpp

	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseArtifacts.h
	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseCreator.h
	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseCreator.cpp
	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseDataSource.h
	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseDataSource.cpp
	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseDataSourceImpl.h
	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseDataSourceImpl.cpp
	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseMigrator.h
	${CMAKE_CURRENT_LIST_DIR}/DataSource/DataBaseMigrator.cpp

	${CMAKE_CURRENT_LIST_DIR}/Enums/AccontType.h

	${CMAKE_CURRENT_LIST_DIR}/Parameters.h
	${CMAKE_CURRENT_LIST_DIR}/SameContainers.h
	)

add_library(PasswordLogicLib STATIC ${SRC_LIST})

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(PasswordLogicLib LINK_PRIVATE ${QT_MODULES_LIST})

target_include_directories(PasswordLogicLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(PasswordLogicLib PRIVATE DataBaseLib)
target_link_libraries(PasswordLogicLib PRIVATE EncryptionLib)
