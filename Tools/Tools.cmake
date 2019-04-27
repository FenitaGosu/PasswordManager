AddTarget(
	NAME Tools
	SOURCE_DIR Tools/
	SRC *.cpp *.h
	QT_USE Core
	SUBDIRS	Random Same StreamWrapper
	)
