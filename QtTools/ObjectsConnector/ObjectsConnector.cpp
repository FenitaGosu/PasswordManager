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

ObjectInfoListMap G_EMITTERS;
ObjectInfoListMap G_RECEIVERS;

constexpr char SIGNAL_PREFIX	= '2';
constexpr char SLOT_PREFIX		= '1';

#define	PRECONDITIONS(VALUE, STR, PREFIX)		\
		assert(VALUE);							\
		assert(std::string(id).length() > 0);	\
		assert(STR && STR[0] == PREFIX);
}

using namespace ObjectsConnector;

void ObjectsConnector::RegisterEmitter(const std::string& id, QObject* emitter, const char* signal)
{
	PRECONDITIONS(emitter, signal, SIGNAL_PREFIX)

	const std::string id_str(id);
	const std::string signal_str(signal);

	G_EMITTERS[id_str].emplace_back(QPointer<QObject>(emitter), signal_str);

	const auto list = G_RECEIVERS.find(id_str);

	if (list == G_RECEIVERS.cend())
		return;

	for (const auto& object : list->second)
		if (!object.first.isNull())
			QObject::connect(emitter, signal, object.first.data(), object.second.c_str());
}

void ObjectsConnector::RegisterReceiver(const std::string& id, QObject* receiver, const char* slot)
{
	PRECONDITIONS(receiver, slot, SLOT_PREFIX)

	const std::string id_str(id);
	const std::string slot_str(slot);

	G_RECEIVERS[id_str].emplace_back(QPointer<QObject>(receiver), slot_str);

	const auto list = G_EMITTERS.find(id_str);

	if (list == G_EMITTERS.cend())
		return;

	for (const auto& object : list->second)
		if (!object.first.isNull())
			QObject::connect(object.first.data(), object.second.c_str(), receiver, slot);
}

void ObjectsConnector::UnregisterEmitter(const std::string& id, QObject* emitter, const char* signal)
{
	PRECONDITIONS(emitter, signal, SIGNAL_PREFIX)

	const std::string id_str(id);
	const std::string signal_str(signal);

	const ObjectInfo objectInfo = std::make_pair(QPointer<QObject>(emitter), signal_str);

	assert(G_EMITTERS.find(id_str) != G_EMITTERS.end());
	assert(std::find(G_EMITTERS[id_str].cbegin(), G_EMITTERS[id_str].cend(), objectInfo) != G_EMITTERS[id_str].end());

	G_EMITTERS[id_str].erase(std::find(G_EMITTERS[id_str].cbegin(), G_EMITTERS[id_str].cend(), objectInfo));

	const auto list = G_RECEIVERS.find(id_str);

	if (list == G_RECEIVERS.cend())
		return;

	for (const auto& object : list->second)
		if (!object.first.isNull())
			QObject::disconnect(emitter, signal, object.first.data(), object.second.c_str());
}

void ObjectsConnector::UnregisterReceiver(const std::string& id, QObject* receiver, const char* slot)
{
	PRECONDITIONS(receiver, slot, SLOT_PREFIX)

	const std::string id_str(id);
	const std::string slot_str(slot);

	const ObjectInfo objectInfo = std::make_pair(QPointer<QObject>(receiver), slot_str);

	assert(G_RECEIVERS.find(id_str) != G_RECEIVERS.end());
	assert(std::find(G_RECEIVERS[id_str].cbegin(), G_RECEIVERS[id_str].cend(), objectInfo) != G_RECEIVERS[id_str].end());

	G_RECEIVERS[id_str].erase(std::find(G_RECEIVERS[id_str].cbegin(), G_RECEIVERS[id_str].cend(), objectInfo));

	const auto list = G_EMITTERS.find(id_str);

	if (list == G_EMITTERS.cend())
		return;

	for (const auto& object : list->second)
		if (!object.first.isNull())
			QObject::disconnect(object.first.data(), object.second.c_str(), receiver, slot);
}
