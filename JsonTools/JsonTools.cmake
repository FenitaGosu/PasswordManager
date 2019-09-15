AddTarget(
	NAME JsonTools
	SOURCE_DIR JsonTools/
	SRC *.cpp *.h
	QT_USE Core
	SUBDIRS
	Interfaces
	ReaderQJson
	)
