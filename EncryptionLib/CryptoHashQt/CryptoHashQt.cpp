#include <QCryptographicHash>
#include <QString>

#include "CryptoHashQt.h"

std::string Encryption::CryptoHashQt::GetMd5(const std::string& msg) const
{
	return QString(QCryptographicHash::hash(msg.c_str(), QCryptographicHash::Md5).toHex()).toStdString();
}

std::string Encryption::CryptoHashQt::GetSha2_256(const std::string& msg) const
{
	return QString(QCryptographicHash::hash(msg.c_str(), QCryptographicHash::Sha256).toHex()).toStdString();
}

std::string Encryption::CryptoHashQt::GetSha3_256(const std::string& msg) const
{
	return QString(QCryptographicHash::hash(msg.c_str(), QCryptographicHash::Sha3_256).toHex()).toStdString();
}
