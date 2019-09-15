#include <cassert>
#include <exception>

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include "ReaderQJson.h"

using namespace JsonTools;

namespace {
const QString MAIN_TAG = "MAIN";
}

ReaderQJson::ReaderQJson(const std::string& filePath)
{
	QFile file(QString::fromStdString(filePath));
	if (!file.open(QFile::ReadOnly))
		throw std::logic_error("File not opened");

	QString str = file.readAll();
	if (str.isEmpty())
		throw std::logic_error("Json file is empty");

	const auto doc = QJsonDocument::fromJson(str.toUtf8()).object();
	if (doc.isEmpty() || !doc.contains(MAIN_TAG))
		throw std::logic_error("Invalid json file or not contains main section \"MAIN\"");

	m_obj = std::make_shared<QJsonObject>(doc.value(MAIN_TAG).toObject());
}

ReaderQJson::ReaderQJson(QJsonObject&& obj)
	: m_obj(std::make_shared<QJsonObject>(std::move(obj)))
{
}

ReaderQJson::~ReaderQJson() = default;

bool ReaderQJson::GetBool(const std::string& key, const bool defaultValue) const
{
	return m_obj->value(QString::fromStdString(key)).toBool(defaultValue);
}

double ReaderQJson::GetDouble(const std::string& key, const double defaultValue) const
{
	return m_obj->value(QString::fromStdString(key)).toDouble(defaultValue);
}

int ReaderQJson::GetInt(const std::string& key, const int defaultValue) const
{
	return m_obj->value(QString::fromStdString(key)).toInt(defaultValue);
}

std::string ReaderQJson::GetString(const std::string& key, const std::string& defaultValue) const
{
	const auto res = m_obj->value(QString::fromStdString(key)).toString().toStdString();
	return res.empty() ? defaultValue : res;
}

std::shared_ptr<IReaderJson> ReaderQJson::GetObject(const std::string& key) const
{
	const auto value = m_obj->value(QString::fromStdString(key));
	assert(value.isObject());
	return std::shared_ptr<IReaderJson>(new ReaderQJson(value.toObject()));
}

bool ReaderQJson::IsContains(const std::string& key) const
{
	return m_obj->contains(QString::fromStdString(key));
}

bool ReaderQJson::IsEmpty() const
{
	return m_obj->empty();
}
