AddTarget(
	NAME DataBase
	SOURCE_DIR DataBase/
	SRC *.cpp *.h
	QT_USE Core Sql
	SUBDIRS
	Interfaces
	SQLiteImpl
	SQLQueryImpl
	)
