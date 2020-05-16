#pragma once

namespace PasswordLogic {

class DataBaseArtifacts
{
public:
	/// Constants
	constexpr inline static int DATABASE_VERSION = 1;

	/// Service constants
	inline static const std::string NAME			= ":name";
	inline static const std::string NAME_INDEX		= "name";

	inline static const std::string VALUE			= ":value";
	inline static const std::string VALUE_INDEX		= "value";

	inline static const std::string ID				= ":id";
	inline static const std::string ID_INDEX		= "id";

	inline static const std::string TYPE			= ":type";
	inline static const std::string TYPE_INDEX		= "type";

	/// Table of constants
	inline static const std::string CREATE_CONSTANT_TABLE		= "CREATE TABLE CONSTANT (name string NOT NULL UNIQUE, value string);";
	inline static const std::string INSERT_CONSTANT				= "INSERT INTO CONSTANT (name, value) VALUES (:name, :value);";
	inline static const std::string SELECT_CONSTANT				= "SELECT value FROM CONSTANT WHERE name = :name;";
	inline static const std::string UPDATE_CONSTANT				= "UPDATE CONSTANT SET value = :value WHERE name = :name;";
	inline static const std::string MAIN_PASSWORD_CONSTANT		= "MainPassword";
	inline static const std::string DATABASE_VERSION_CONSTANT	= "DataBaseVersion";

	/// Table of Accounts
	inline static const std::string CREATE_ACCOUNT_TABLE	= "CREATE TABLE ACCOUNT (id varchar(255) NOT NULL PRIMARY KEY, name string, type string);";
	inline static const std::string INSERT_ACCOUNT			= "INSERT INTO ACCOUNT (id, name, type) VALUES (:id, :name, :type);";
	inline static const std::string SELECT_ACCOUNT			= "SELECT * FROM ACCOUNT;";
};

}
