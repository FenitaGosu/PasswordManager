#pragma once

#include <memory>

namespace DataBase {
class IDataBaseConnection;
}

namespace PasswordLogic {

class DataBaseCreator
{
public:
	static void FillDataBase(const std::unique_ptr<DataBase::IDataBaseConnection>& connection);
};

}
