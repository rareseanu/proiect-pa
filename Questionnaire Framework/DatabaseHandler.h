#pragma once
#include <iostream>
#include <vector>
#include <libpq-fe.h>
#include "Question.h"
class DatabaseHandler
{
public:
	DatabaseHandler(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
					const  std::string& databaseUser, const std::string& databasePassword);
	DatabaseHandler(const std::string& databaseName, const std::string& databaseHost,
					const  std::string& databaseUser, const std::string& databasePassword);
	std::vector<std::vector<std::string>> getTable(const std::string& denumire);
	void printTable(const std::vector<std::vector<std::string>>& table);
	bool isConnected();

private:
	PGconn* conn;
};

