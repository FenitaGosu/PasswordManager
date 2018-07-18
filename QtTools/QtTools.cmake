AddTarget(
	NAME QtTools
	SOURCE_DIR QtTools/
	SRC *.cpp *.h
	QT_USE Core Widgets
	SUBDIRS	ObjectsConnector
	)
