#include <iostream>
#include <stdio.h>
#include "sqlite3.h"
#include <vector>
#include <string>

int main() {

    sqlite3* db;
    int rc = sqlite3_open(":memory:", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    std::cout << "Opened database successfully" << std::endl;
    sqlite3_close(db);
    return 0;
}