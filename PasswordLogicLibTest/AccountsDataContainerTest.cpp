#include <memory>

#include <QString>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ToolsLib/Same/Same.h"
#include "EncryptionLib/EmptyEncryptor/EmptyEncryptor.h"

#include "PasswordLogicLib/DataContainer/AccountsDataContainer.h"
#include "PasswordLogicLib/AccountInfo/AccountInfo.h"
#include "PasswordLogicLib/Enums/AccontType.h"
#include "PasswordLogicLib/Parameters.h"
#include "PasswordLogicLib/SameContainers.h"

using namespace PasswordLogic;
using namespace Encryption;

TEST(AccountsDataContainer, GetAllInfoAndAddDataListTest)
{
	auto container = std::make_unique<AccountsDataContainer>(std::make_unique<Encryption::EmptyEncryptor>());

	const std::string id	= "e403d007-5791-4c5b-b745-cdc2d55039b9";
	const std::string name	= "TestName";
	const AccountType type	= AccountType::Simple;

	DataList data;
	{
		Data mapData;

		mapData.emplace(Parameters::PARAM_ID	, id);
		mapData.emplace(Parameters::PARAM_NAME	, name);
		mapData.emplace(Parameters::PARAM_TYPE	, std::to_string(static_cast<int>(type)));

		data.push_back(mapData);
	}

	container->AddDataList(std::move(data));

	const auto info = container->GetAllInfo();

	ASSERT_EQ(info.size(), 1);
	ASSERT_EQ(info.front().GetId().toStdString(), id);
	ASSERT_EQ(info.front().GetName().toStdString(), name);
	ASSERT_EQ(info.front().GetType(), type);
}

TEST(AccountsDataContainer, GetDataListTest)
{
	const QString		id		= "e403d007-5791-4c5b-b745-cdc2d55039b9";
	const QString		name	= "TestName";
	const AccountType	type	= AccountType::Simple;

	const AccountsInfo info{ {id, name, type} };
	const auto container = std::make_unique<AccountsDataContainer>(std::make_unique<Encryption::EmptyEncryptor>(), info);

	const auto data = container->GetDataList();
	ASSERT_EQ(data.size(), 1);

	const auto mapData = data.front();
	ASSERT_EQ(mapData.size(), 3);

	const auto getValue = [](const Data& data, const std::string& key)
	{
		const auto it = data.find(key);
		assert(it != data.cend());
		return QString::fromStdString(it->second.Get<const std::string&>());
	};

	ASSERT_EQ(getValue(mapData, Parameters::PARAM_ID)	, id);
	ASSERT_EQ(getValue(mapData, Parameters::PARAM_NAME)	, name);
	ASSERT_EQ(getValue(mapData, Parameters::PARAM_TYPE)	, QString::number(static_cast<int>(type)));
}

TEST(AccountsDataContainer, GetDataTest)
{
	const QString		id		= "e403d007-5791-4c5b-b745-cdc2d55039b9";
	const QString		name	= "TestName";
	const AccountType	type	= AccountType::Simple;

	const AccountsInfo info{ {id, name, type} };
	const auto container = std::make_unique<AccountsDataContainer>(std::make_unique<Encryption::EmptyEncryptor>(), info);

	const auto mapData = container->GetData();

	ASSERT_EQ(mapData.size(), 3);

	const auto getValue = [](const Data& data, const std::string& key)
	{
		const auto it = data.find(key);
		assert(it != data.cend());
		return QString::fromStdString(it->second.Get<const std::string&>());
	};

	ASSERT_EQ(getValue(mapData, Parameters::PARAM_ID)	, id);
	ASSERT_EQ(getValue(mapData, Parameters::PARAM_NAME)	, name);
	ASSERT_EQ(getValue(mapData, Parameters::PARAM_TYPE)	, QString::number(static_cast<int>(type)));
}

TEST(AccountsDataContainer, GetAllInfoAndAddDataTest)
{
	auto container = std::make_unique<AccountsDataContainer>(std::make_unique<Encryption::EmptyEncryptor>());

	const std::string id	= "e403d007-5791-4c5b-b745-cdc2d55039b9";
	const std::string name	= "TestName";
	const AccountType type	= AccountType::Simple;

	{
		Data mapData;
		mapData.emplace(Parameters::PARAM_ID	, id);
		mapData.emplace(Parameters::PARAM_NAME	, name);
		mapData.emplace(Parameters::PARAM_TYPE	, std::to_string(static_cast<int>(type)));
		container->AddData(std::move(mapData));
	}

	const auto info = container->GetAllInfo();

	ASSERT_EQ(info.size(), 1);
	ASSERT_EQ(info.front().GetId().toStdString(), id);
	ASSERT_EQ(info.front().GetName().toStdString(), name);
	ASSERT_EQ(info.front().GetType(), type);
}
