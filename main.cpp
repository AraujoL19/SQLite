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
    insertInputData(dir, 2, "ModelParams2");
    insertModelData(dir, 2, "ModelDescription2", 2);
    insertOutputData(dir, 2, 2, 2, "Results2");
    insertSimulationData(dir, 2, 2, 30, "simulation run2");

    //prints data from tables
    checkTableData(dir, "INPUT");
    checkTableData(dir, "MODEL");
    checkTableData(dir, "OUTPUT");
    checkTableData(dir, "SIMULATION");


    return 0;
}