#pragma once
#include <iostream>
#include <vector>
#include <libpq-fe.h>
#include "Question.h"
#include <memory>
class DatabaseHandler
{
public:
	__declspec(dllexport) DatabaseHandler(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
		const  std::string& databaseUser, const std::string& databasePassword);
	__declspec(dllexport) DatabaseHandler(const std::string& databaseName, const std::string& databaseHost,
		const  std::string& databaseUser, const std::string& databasePassword);

	__declspec(dllexport) const std::vector<std::vector<std::string>> GetTable(const std::string& tableName);
	__declspec(dllexport) const std::vector<std::vector<std::string>> GetTableFromCommand(const std::string& command);

	__declspec(dllexport) void RunCommand(const std::string& command);
	__declspec(dllexport) void PrintTable(const std::vector<std::vector<std::string>>& table) const;
	__declspec(dllexport) bool IsConnected();

private:
	PGconn* conn;
};

