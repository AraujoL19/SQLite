#include <iostream>
#include <stdio.h>
#include "sqlite3.h"

using namespace std;

static int createDB(const char* s){
    sqlite3* db;
    int exit = 0;
    exit = sqlite3_open(s, &db);
    sqlite3_close(db);

    return 0;
}

static int createSimulationTable(const char* s){
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS SIMULATION("
    "SIMULATION_ID INTEGER PRIMARY KEY, "
    "OUTPUT_ID INTEGER NOT NULL, "
    "TIME_DAYS INTEGER NOT NULL, "
    "SIMULATION_STATUS TEXT NOT NULL, "
    "FOREIGN KEY (OUTPUT_ID) REFERENCES OUTPUT(OUTPUD_ID));";

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

static int createOutputTable(const char* s){
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS OUTPUT("
    "OUTPUT_ID INTEGER PRIMARY KEY AUTOINCREMENT, "
    "MODEL_ID INTEGER NOT NULL, "
    "INPUT_ID NOT NULL, "
    "RESULTS TEXT NOT NULL, "
    "FOREIGN KEY (MODEL_ID) REFERENCES MODEL(MODEL_ID), "
    "FOREIGN KEY (INPUT_ID) REFERENCES INPUT(INPUD_ID));";

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

static int createModelTable(const char* s){
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS MODEL("
    "MODEL_ID INTEGER PRIMARY KEY AUTOINCREMENT, "
    "MODEL_DESCRIPTION TEXT NOT NULL, "
    "MODEL_VERSION INTEGER NOT NULL);";

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

static int createInputTable(const char* s){
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS INPUT("
    "INPUT_ID INTEGER PRIMARY KEY AUTOINCREMENT, "
    "CORTISOL_EXP_PARAMETERS TEXT NOT NULL, "
    "SIMULATION_GENDER CHAR(1) NOT NULL, "
    "INITIAL_CONDITIONS TEXT NOT NULL);";

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

    string sql("INSERT INTO INPUT (INPUT_ID, CORTISOL_EXP_PARAMETERS, SIMULATION_GENDER, INITIAL_CONDITIONS) VALUES(1, 'cortisolExp', 'F', 'initialConditions');"
    "INSERT INTO MODEL (MODEL_ID, MODEL_DESCRIPTION, MODEL_VERSION) VALUES(1, 'modelDescription', 10);"
    "INSERT INTO OUTPUT (OUTPUT_ID, MODEL_ID, INPUT_ID, RESULTS) VALUES(1, 1, 1, 'results');"
    "INSERT INTO SIMULATION (SIMULATION_ID, OUTPUT_ID, TIME_DAYS, SIMULATION_STATUS) VALUES(1, 1, 365, 'simulation run');");

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
    const char* dir = "/home/araujol/Documentos/Araujo/SQLite/Teste.db";
    //const char* dir = "C:\Users\yldog\OneDrive\Documentos\ICimunoendocrino";
    sqlite3* DB;

    createDB(dir);
    createInputTable(dir);
    createModelTable(dir);
    createOutputTable(dir);
    createSimulationTable(dir);
    insertData(dir);
    //sqlite3_api was not declared in this scope, 12 29 56 82 109 130 sqlite3_open()
    return 0;
}