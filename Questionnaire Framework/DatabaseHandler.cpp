#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler(const std::string& databaseName, const std::string &databaseHost, const std::string &databasePort,
								const  std::string &databaseUser, const std::string &databasePassword) {
	std::string connectString="";
	connectString = connectString + "dbname = " + databaseName + " host = " + databaseHost +" port = "+ databasePort+ " user = " + databaseUser +" password = " + databasePassword;
	conn = PQconnectdb(connectString.c_str());
}
DatabaseHandler::DatabaseHandler(const std::string& databaseName, const std::string& databaseHost,
								const  std::string& databaseUser, const std::string& databasePassword) {
	std::string connectString = "";
	connectString = connectString + "dbname = " + databaseName + " host = " + databaseHost +" user = " + databaseUser +" password = " + databasePassword;
	conn = PQconnectdb(connectString.c_str());
}
std::vector<std::vector<std::string>> DatabaseHandler::getTable(const std::string& denumire) {

    std::vector<std::vector<std::string>> table;
    std::string sqlCommand = "select * from ";
    sqlCommand = sqlCommand + denumire;
    PGresult* res = PQexec(conn, sqlCommand.c_str());
    int recCount = PQntuples(res);
    int colNumber = PQnfields(res);
    for (int row = 0; row < recCount; row++) {
        table.push_back(std::vector<std::string>());
        for (int column = 0; column < colNumber; column++) {
            std::string value = PQgetvalue(res, row, column);
            table[row].push_back(value);
        }
    }
    return table;
}

std::vector<std::vector<std::string>> DatabaseHandler::getTableFromCommand(const std::string& comanda) {

    std::vector<std::vector<std::string>> table;
    std::string sqlCommand = comanda;
    PGresult* res = PQexec(conn, sqlCommand.c_str());
    int recCount = PQntuples(res);
    int colNumber = PQnfields(res);
    for (int row = 0; row < recCount; row++) {
        table.push_back(std::vector<std::string>());
        for (int column = 0; column < colNumber; column++) {
            std::string value = PQgetvalue(res, row, column);
            table[row].push_back(value);
        }
    }
    return table;
}
void DatabaseHandler::printTable(const std::vector<std::vector<std::string>>& table) const {
    for (std::vector<std::string> i : table) {
        for (std::string value : i) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
bool DatabaseHandler::isConnected()
{
	if(PQstatus(conn)==CONNECTION_OK){
		return true;
	}
	return false;
}
