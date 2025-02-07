#include <stdio.h>
#include <sqlite3.h>
#include <iostream>

using namespace std;


static int createDB(const char* s){
    sqlite3* DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);

    sqlite3_close(DB);

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
        exit = sqlite3_open(s, &DB);
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

        if(exit != SQLITE_OK){
            cerr << "Error create table" << endl;
            sqlite3_free(messageError);
        }else{
            cout<<"Table created sucessfully" << endl;
        }
        sqlite3_close(DB);
    }catch(const exception & e){
        cerr<<e.what();
    }
    return 0;
}

static int insertData(const char* s){
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    string sql("INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Alice', 'Chapa', 35, 'Tampa', 'A');"
    "INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Bob', 'Lee', 20, 'Dallas', 'B');"
    "INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Fred', 'Cooper', 24, 'New York', 'C');");

    exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);
    if(exit != SQLITE_OK){
        cerr<<"error insert"<<endl;
        sqlite3_free(messageError);
    }else{
        cout<<"Records created sucessfully"<<endl;
    }
    return 0;
}

int main(){
    const char* dir = "/home/araujol/Documentos/Araujo/SQLite/sqlite-tools-linux-x64-3470000/Teste.db";
    sqlite3* DB;

    createDB(dir);
    createTable(dir);
    insertData(dir);
    
    return 0;
}