#pragma once

#include <string>

class QObject;

namespace ObjectsConnector {

void RegisterEmitter	(const std::string& id, QObject* emitter,	const char* signal);
void RegisterReceiver	(const std::string& id, QObject* receiver,	const char* slot);
void UnregisterEmitter	(const std::string& id, QObject* emitter,	const char* signal);
void UnregisterReceiver	(const std::string& id, QObject* receiver,	const char* slot);

}
