#include <stdio.h>
#include <sqlite3.h>
#include <sqlite3ext.h>
#include <iostream>

using namespace std;

static int createDB(const char* s);
static int createTable(const char* s);

int main(){
    const char* dir = "c:/home/araujol/Documentos/Araujo/SQLite";
    sqlite3* DB;

    createDB(dir);
    createTable(dir);
    
    return 0;
}

static int createTable(const char* s){
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS GRADES("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
    "NAME TEXT NOT NULL, "
    "LNAME TEXT NOT NULL, "
    "AGE INT NOT NULL, "
    "ADDRESS CHAR(50), "
    "GRADE CHAR(1) );";

    try{
        int exit = 0;
        exit = sqlite_open(s, &DB);
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    }
}