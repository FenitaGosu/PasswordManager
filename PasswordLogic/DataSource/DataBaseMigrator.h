#pragma once

#include <memory>

namespace DataBase {
class IDataBaseConnection;
}

namespace PasswordLogic {

class DataBaseMigrator
{
public:
	static void MigrateDataBase(const std::unique_ptr<DataBase::IDataBaseConnection>& connection);
};

}
