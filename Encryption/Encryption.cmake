AddTarget(
	NAME Encryption
	SOURCE_DIR Encryption/
	SRC *.cpp *.h
	QT_USE Core
	SUBDIRS
	Interfaces
	XOREncryptor
	SimpleKeyProvider
	CryptoHashQt
	)
