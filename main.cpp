#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "sqlite3.h"
#include <vector>
#include <string>
#include "database_operations.h"

using namespace std;

int main(){

    //diretorio linux do PPGMC
    //const char* dir = "/home/araujol/Documentos/Araujo/SQLite/Teste.db";
    
    //diretorio windows pessoal
    const char* dir = "C:/Users/yldog/OneDrive/Documentos/ICimunoendocrino/SQLite/Database1.db";
    const char* json = "C:/Users/yldog/OneDrive/Documentos/ICimunoendocrino/SQLite/params.json";
    
    //declara a DB
    sqlite3* DB;
    
    //cria a DB no diretorio
    createDB(dir);
    
    //creates tables in the database
    createInputTable(dir);
    createModelTable(dir);
    createOutputTable(dir);
    createSimulationTable(dir);

    //inserts data from functions
    insertInputData(dir, 3, json);
    //insertInputData(dir, 2, "ModelParams2");
    insertModelData(dir, 3, "ModelDescription3", 3);
    insertOutputData(dir, 3, 3, 3, "Results3");
    insertSimulationData(dir, 3, 3, 7, "simulation run3");

    //prints data from tables
    checkTableData(dir, "INPUT");
    checkTableData(dir, "MODEL");
    checkTableData(dir, "OUTPUT");
    checkTableData(dir, "SIMULATION");


    return 0;
}