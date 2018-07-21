#pragma once

#include <QString>

namespace PasswordLogic {

class DataBaseArtifacts
{
public:
	/// Constants
	constexpr inline static int DATABASE_VERSION = 1;

	/// Service constants
	inline static const QString NAME =		":name";
	inline static const QString VALUE		= ":value";
	inline static const QString VALUE_INDEX	= "value";

	/// Table of constants
	inline static const QString CREATE_CONSTANT_TABLE		= "CREATE TABLE CONSTANT (name string NOT NULL UNIQUE, value string);";
	inline static const QString INSERT_CONSTANT				= "INSERT INTO CONSTANT (name, value) VALUES (:name, :value);";
	inline static const QString SELECT_CONSTANT				= "SELECT value FROM CONSTANT WHERE name = :name;";
	inline static const QString UPDATE_CONSTANT				= "UPDATE CONSTANT SET value = :value WHERE name = :name;";
	inline static const QString MAIN_PASSWORD_CONSTANT		= "MainPassword";
	inline static const QString DATABASE_VERSION_CONSTANT	= "DataBaseVersion";
};

}
