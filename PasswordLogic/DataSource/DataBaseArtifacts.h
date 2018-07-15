#pragma once

#include <QString>

namespace PasswordLogic {

class DataBaseArtifacts
{
public:
	inline static const QString CREATE_MAIN_PASSWORD_TABLE	= "CREATE TABLE MAIN_PASSWORD (password string);";
	inline static const QString INSERT_MAIN_PASSWORD		= "INSERT INTO MAIN_PASSWORD (password) VALUES (:password);";
	inline static const QString SELECT_MAIN_PASSWORD		= "SELECT password FROM MAIN_PASSWORD;";
	inline static const QString UPDATE_MAIN_PASSWORD		= "UPDATE MAIN_PASSWORD SET password = :password;";
};

}
