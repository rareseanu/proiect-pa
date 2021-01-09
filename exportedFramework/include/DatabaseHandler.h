#pragma once
#include <iostream>
#include <vector>
#include <libpq-fe.h>
#include "Question.h"
class __declspec(dllexport) DatabaseHandler
{
public:
	DatabaseHandler(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
					const  std::string& databaseUser, const std::string& databasePassword);
	DatabaseHandler(const std::string& databaseName, const std::string& databaseHost,
					const  std::string& databaseUser, const std::string& databasePassword);
	std::vector<std::vector<std::string>> GetTable(const std::string& tableName);
	std::vector<std::vector<std::string>> GetTableFromCommand(const std::string& command);
	void RunCommand(const std::string& command);
	void PrintTable(const std::vector<std::vector<std::string>>& table) const;
	bool IsConnected();

private:
	PGconn* conn;
};

