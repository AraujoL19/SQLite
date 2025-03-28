#include "database_operations.h"
#include "sqlite3.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int createDB(const char* s) {
    sqlite3* db;
    int exit = sqlite3_open(s, &db);
    sqlite3_close(db);
    return 0;
}

int createInputTable(const char* s) {
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS INPUT("
        "INPUT_ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "MODEL_PARAMETERS TEXT NOT NULL"");";

    try {
        int exit = sqlite3_open(s, &DB);
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

        if(exit != SQLITE_OK) {
            cerr << "Error create table" << endl;
            sqlite3_free(messageError);
        } else {
            cout << "Table created sucessfully" << endl;
        }
        sqlite3_close(DB);
    } catch(const exception & e) {
        cerr << e.what();
    }
    return 0;
}

int createModelTable(const char* s){
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
            cout<<"MODEL table created sucessfully" << endl;
        }
        sqlite3_close(DB);
    }catch(const exception & e){
        cerr<<e.what();
    }
    return 0;
}

int createOutputTable(const char* s){
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS OUTPUT("
    "OUTPUT_ID INTEGER PRIMARY KEY AUTOINCREMENT, "
    "MODEL_ID INTEGER NOT NULL, "
    "INPUT_ID NOT NULL, "
    "RESULTS TEXT NOT NULL, "
    "FOREIGN KEY (MODEL_ID) REFERENCES MODEL(MODEL_ID), "
    "FOREIGN KEY (INPUT_ID) REFERENCES INPUT(INPUT_ID));";

    try{
        int exit = 0;
        exit = sqlite3_open(s, &DB);
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

        if(exit != SQLITE_OK){
            cerr << "Error create table" << endl;
            sqlite3_free(messageError);
        }else{
            cout<<"OUTPUT table created sucessfully" << endl;
        }
        sqlite3_close(DB);
    }catch(const exception & e){
        cerr<<e.what();
    }
    return 0;
}

int createSimulationTable(const char* s){
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS SIMULATION("
    "SIMULATION_ID INTEGER PRIMARY KEY, "
    "OUTPUT_ID INTEGER NOT NULL, "
    "TIME_DAYS INTEGER NOT NULL, "
    "SIMULATION_STATUS TEXT NOT NULL, "
    "FOREIGN KEY (OUTPUT_ID) REFERENCES OUTPUT(OUTPUT_ID));";

    try{
        int exit = 0;
        exit = sqlite3_open(s, &DB);
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

        if(exit != SQLITE_OK){
            cerr << "Error create table" << endl;
            sqlite3_free(messageError);
        }else{
            cout<<"SIMULATION table created sucessfully" << endl;
        }
        sqlite3_close(DB);
    }catch(const exception & e){
        cerr<<e.what();
    }
    return 0;
}

int insertInputData(const char* s, int inputId, const string& cortisolExpParams, 
                         char simulationGender, const string& initialConditions) {
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(s, &DB);

    string sql = "INSERT INTO INPUT (INPUT_ID, CORTISOL_EXP_PARAMETERS, SIMULATION_GENDER, INITIAL_CONDITIONS) VALUES("
        + to_string(inputId) + ", '" + cortisolExpParams + "', '" + simulationGender + "', '" + initialConditions + "');"; 
    exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);
    if(exit != SQLITE_OK) {
        cerr << "Error inserting into INPUT: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Record inserted into INPUT sucessfully" << endl;
    }
    sqlite3_close(DB);
    return exit;
}

int insertModelData(const char* s, int modelId, const string& modelDescription, int modelVersion){
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(s, &DB);

    string sql = "INSERT INTO MODEL (MODEL_ID, MODEL_DESCRIPTION, MODEL_VERSION) VALUES("
        + to_string(modelId) + ", '" + modelDescription + "', " + to_string(modelVersion) + ");"; 
    exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);
    if(exit != SQLITE_OK){
        cerr<<"Error inserting into MODEL table: "<<messageError<<endl;
        sqlite3_free(messageError);
    }else{
        cout<<"Record inserted into MODEL table sucessfully"<<endl;
    }
    sqlite3_close(DB);
    return exit;
}

int insertOutputData(const char* s, int outputId, int modelId, int inputId, const string& results){
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(s, &DB);

    string sql = "INSERT INTO OUTPUT (OUTPUT_ID, MODEL_ID, INPUT_ID, RESULTS) VALUES("
        + to_string(outputId) + ", " + to_string(modelId) + ", " + to_string(inputId) + ", '" + results + "');"; 
    exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);
    if(exit != SQLITE_OK){
        cerr<<"Error inserting into OUTPUT table: "<<messageError<<endl;
        sqlite3_free(messageError);
    }else{
        cout<<"Record inserted into OUTPUT table sucessfully"<<endl;
    }
    sqlite3_close(DB);
    return exit;
}

int insertSimulationData(const char* s, int simulationId, int outputId, int timeDays, const string& simulationStatus){
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(s, &DB);

    string sql = "INSERT INTO SIMULATION (SIMULATION_ID, OUTPUT_ID, TIME_DAYS, SIMULATION_STATUS) VALUES("
        + to_string(simulationId) + ", " + to_string(outputId) + ", " + to_string(timeDays) + ", '" + simulationStatus + "');"; 
    exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);
    if(exit != SQLITE_OK){
        cerr<<"Error inserting into SIMULATION table: "<<messageError<<endl;
        sqlite3_free(messageError);
    }else{
        cout<<"Record inserted into SIMULATION table sucessfully"<<endl;
    }
    sqlite3_close(DB);
    return exit;
}

int insertGeneralData(const char* s) {
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(s, &DB);

    string sql("INSERT INTO INPUT (INPUT_ID, CORTISOL_EXP_PARAMETERS, SIMULATION_GENDER, INITIAL_CONDITIONS) VALUES(1, 'cortisolExp', 'F', 'initialConditions');"
    "INSERT INTO MODEL (MODEL_ID, MODEL_DESCRIPTION, MODEL_VERSION) VALUES(1, 'modelDescription', 10);"
    "INSERT INTO OUTPUT (OUTPUT_ID, MODEL_ID, INPUT_ID, RESULTS) VALUES(1, 1, 1, 'results');"
    "INSERT INTO SIMULATION (SIMULATION_ID, OUTPUT_ID, TIME_DAYS, SIMULATION_STATUS) VALUES(1, 1, 365, 'simulation run');");

    exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);
    if(exit != SQLITE_OK) {
        cerr << "error insert" << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Records created sucessfully" << endl;
    }
    return 0;
}