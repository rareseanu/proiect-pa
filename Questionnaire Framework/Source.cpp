#include <iostream>
#include <iomanip>
#include "DatabaseHandler.h"


int main() {
    std::vector<std::vector<std::string>> intrebari;
    DatabaseHandler dh("yufioaba","ruby.db.elephantsql.com","5432","yufioaba","ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
    if (dh.isConnected()) {
        dh.printTable(dh.getTable("intrebari"));
    }
    else {
        std::cout << "Nu esti conectat!";
    }
}
