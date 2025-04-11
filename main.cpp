#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "sqlite3.h"
#include <vector>
#include <string>
#include "database_operations.h"

using namespace std;

int main(){

    //parar de imprimir o conteúdo do json e imprimir o titulo

    //diretorio linux do PPGMC
    //const char* dir = "/home/araujol/Documentos/Araujo/SQLite/Teste.db";
    
    //diretorio windows pessoal
    const char* database = "C:/Users/yldog/OneDrive/Documentos/ICimunoendocrino/SQLite/Database1.db";
    const char* json = "C:/Users/yldog/OneDrive/Documentos/ICimunoendocrino/SQLite/params.json";
    
    //declara a DB
    sqlite3* DB;
    
    //cria a DB no diretorio
    createDB(database);
    
    //creates tables in the database
    createInputTable(database);
    createModelTable(database);
    createOutputTable(database);
    createSimulationTable(database);

    //inserts data from functions
    insertInputData(database, 3, json);
    //insertInputData(dir, 2, "ModelParams2");
    insertModelData(database, 3, "ModelDescription3", 3);
    insertOutputData(database, 3, 3, 3, "Results3");
    insertSimulationData(database, 3, 3, 7, "simulation run3");

    //prints data from tables
    checkTableData(database, "INPUT");
    checkTableData(database, "MODEL");
    checkTableData(database, "OUTPUT");
    checkTableData(database, "SIMULATION");


    return 0;
}