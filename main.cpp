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
    insertInputData(dir, 1, "ModelParams");
    insertModelData(dir, 1, "ModelDescription", 1);
    insertOutputData(dir, 1, 1, 1, "Results");
    insertSimulationData(dir, 1, 1, 365, "simulation run");

    //prints data from tables
    checkTableData(dir, "INPUT");
    checkTableData(dir, "MODEL");
    checkTableData(dir, "OUTPUT");
    checkTableData(dir, "SIMULATION");


    return 0;
}