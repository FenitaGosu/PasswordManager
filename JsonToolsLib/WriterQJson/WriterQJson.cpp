#include <exception>

#include <QJsonDocument>
#include <QJsonObject>

#include "ToolsLib/StringFormat/StringFormat.h"

#include "WriterQJson.h"

namespace {
	const QString MAIN_TAG = "MAIN";
}

using namespace JsonTools;

struct WriterQJson::Impl
{
	void Contains(const std::string& key)
	{
		if (values.contains(QString::fromStdString(key)))
			throw std::logic_error(Tools::StringFormat::Format("Key %s alredy contains in json", key.c_str()));
	}

	QJsonObject values;
};

WriterQJson::WriterQJson()
	: m_impl(std::make_unique<Impl>())
{
}

WriterQJson::~WriterQJson() = default;

void WriterQJson::AddBool(const std::string& key, bool value)
{
	m_impl->Contains(key);
	m_impl->values.insert(QString::fromStdString(key), value);
}

void WriterQJson::AddDouble(const std::string& key, double value)
{
	m_impl->Contains(key);
	m_impl->values.insert(QString::fromStdString(key), value);
}

void WriterQJson::AddInt(const std::string& key, int value)
{
	m_impl->Contains(key);
	m_impl->values.insert(QString::fromStdString(key), value);
}

void WriterQJson::AddString(const std::string& key, const std::string& value)
{
	m_impl->Contains(key);
	m_impl->values.insert(QString::fromStdString(key), QString::fromStdString(value));
}

void WriterQJson::AddObject(const std::string& key, const std::shared_ptr<IWriterJson>& object)
{
	m_impl->Contains(key);

	const auto writerQJsonObjet = std::dynamic_pointer_cast<WriterQJson>(object);

	if (!writerQJsonObjet)
		throw std::runtime_error("object is not WriterQJson");

	m_impl->values.insert(QString::fromStdString(key), writerQJsonObjet->m_impl->values);
}

std::string WriterQJson::Serialize() const
{
	const QJsonObject main({{ MAIN_TAG , m_impl->values }});
	const QJsonDocument doc(main);

	return doc.toJson().toStdString();
}
