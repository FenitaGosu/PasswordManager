set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IDataBaseConnection.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/IQuery.h
	${CMAKE_CURRENT_LIST_DIR}/Interfaces/ITransactionManager.h

	${CMAKE_CURRENT_LIST_DIR}/DataBaseConnectionSQL/DataBaseConnectionSQL.h
	${CMAKE_CURRENT_LIST_DIR}/DataBaseConnectionSQL/DataBaseConnectionSQL.cpp

	${CMAKE_CURRENT_LIST_DIR}/QuerySQL/QuerySQL.h
	${CMAKE_CURRENT_LIST_DIR}/QuerySQL/QuerySQL.cpp

	${CMAKE_CURRENT_LIST_DIR}/TransactionManagerSQL/TransactionGuard.h
	${CMAKE_CURRENT_LIST_DIR}/TransactionManagerSQL/TransactionGuard.cpp
	${CMAKE_CURRENT_LIST_DIR}/TransactionManagerSQL/TransactionManagerSQL.h
	${CMAKE_CURRENT_LIST_DIR}/TransactionManagerSQL/TransactionManagerSQL.cpp
	)

add_library(DataBaseLib STATIC ${SRC_LIST})

target_include_directories(DataBaseLib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

set(QT_MODULES_LIST
	Core
	Sql
	)

qt5_use_modules(DataBaseLib LINK_PRIVATE ${QT_MODULES_LIST})
