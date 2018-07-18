#include <cassert>
#include <string>
#include <map>
#include <algorithm>

#include <QObject>
#include <QPointer>

#include "ObjectsConnector.h"

namespace {

using ObjectInfo		= std::pair<QPointer<QObject>, std::string>;
using ObjectInfoList	= std::list<ObjectInfo>;
using ObjectInfoListMap	= std::map<std::string, ObjectInfoList>;

ObjectInfoListMap emitters;
ObjectInfoListMap receivers;

constexpr char SIGNAL_PREFIX	= '2';
constexpr char SLOT_PREFIX		= '1';

}

using namespace ObjectsConnector;

void ObjectsConnector::RegisterEmitter(const std::string& id, QObject* emitter, const char* signal)
{
	assert(emitter);
	assert(std::string(id).length() > 0);
	assert(signal && signal[0] == SIGNAL_PREFIX);

	const std::string id_str(id);
	const std::string signal_str(signal);

	emitters[id_str].emplace_back(QPointer<QObject>(emitter), signal_str);

	const auto list = receivers.find(id_str);

	if (list == receivers.cend())
		return;

	for (const auto& object : list->second)
		if (!object.first.isNull())
			QObject::connect(emitter, signal, object.first.data(), object.second.c_str());
}

void ObjectsConnector::RegisterReceiver(const std::string& id, QObject* receiver, const char* slot)
{
	assert(receiver);
	assert(std::string(id).length() > 0);
	assert(slot && slot[0] == SLOT_PREFIX);

	const std::string id_str(id);
	const std::string slot_str(slot);

	receivers[id_str].emplace_back(QPointer<QObject>(receiver), slot_str);

	const auto list = emitters.find(id_str);

	if (list == emitters.cend())
		return;

	for (const auto& object : list->second)
		if (!object.first.isNull())
			QObject::connect(object.first.data(), object.second.c_str(), receiver, slot);
}

void ObjectsConnector::UnregisterEmitter(const std::string& id, QObject* emitter, const char* signal)
{
	assert(emitter);
	assert(std::string(id).length() > 0);
	assert(signal && signal[0] == SIGNAL_PREFIX);

	const std::string id_str(id);
	const std::string signal_str(signal);

	const ObjectInfo objectInfo = std::make_pair(QPointer<QObject>(emitter), signal_str);
	assert(emitters.find(id_str) != emitters.end());
	assert(std::find(emitters[id_str].begin(), emitters[id_str].end(), objectInfo) != emitters[id_str].end());
	emitters[id_str].erase(std::find(emitters[id_str].begin(), emitters[id_str].end(), objectInfo));

	const auto list = receivers.find(id_str);

	if (list == receivers.cend())
		return;

	for (const auto& object : list->second)
		if (!object.first.isNull())
			QObject::disconnect(emitter, signal, object.first.data(), object.second.c_str());
}

void ObjectsConnector::UnregisterReceiver(const std::string& id, QObject* receiver, const char* slot)
{
	assert(receiver);
	assert(std::string(id).length() > 0);
	assert(slot && slot[0] == SLOT_PREFIX);

	const std::string id_str(id);
	const std::string slot_str(slot);

	const ObjectInfo objectInfo = std::make_pair(QPointer<QObject>(receiver), slot_str);
	assert(receivers.find(id_str) != receivers.end());
	assert(std::find(receivers[id_str].begin(), receivers[id_str].end(), objectInfo) != receivers[id_str].end());
	receivers[id_str].erase(std::find(receivers[id_str].begin(), receivers[id_str].end(), objectInfo));

	const auto& list = emitters.find(id_str);

	if (list == emitters.cend())
		return;

	for (const auto& object : list->second)
		if (!object.first.isNull())
			QObject::disconnect(object.first.data(), object.second.c_str(), receiver, slot);
}
