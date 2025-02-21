#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <sqlite3ext.h>

using namespace std;

// cria as tabelas
void createTables(sqlite3* db) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS input (
            input_id INTEGER PRIMARY KEY,
            cortisol_exp_parameters TEXT,
            simulation_gender VARCHAR(1),
            initial_conditions TEXT
        );

        CREATE TABLE IF NOT EXISTS simulation (
            simulation_id INTEGER PRIMARY KEY,
            output_id INTEGER,
            time_days INTEGER,
            simulation_status TEXT,
            FOREIGN KEY(output_id) REFERENCES output(output_id)
        );

        CREATE TABLE IF NOT EXISTS model (
            model_id INTEGER PRIMARY KEY,
            model_description TEXT,
            model_version INTEGER
        );

        CREATE TABLE IF NOT EXISTS output (
            output_id INTEGER PRIMARY KEY,
            model_id INTEGER,
            input_id INTEGER,
            results TEXT,
            FOREIGN KEY(model_id) REFERENCES model(model_id),
            FOREIGN KEY(input_id) REFERENCES input(input_id)
        );
    )";

    char* errorMessage;

    //executa comandos sqlite na db
    int rc = sqlite3_exec(db, sql, 0, 0, &errorMessage);
    
    if (rc != SQLITE_OK) {
        cerr << "Erro ao criar tabelas: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    } else {
        cout << "Tabelas criadas com sucesso!" << endl;
    }
}

int main() {
    //declara uma db do tipo sqlite3
    sqlite3* db;
    //funcao open
    int rc = sqlite3_open("simulation.db", &db);
    
    //verifica se abriu o banco de dados
    if (rc) {
        cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << endl;
        return rc;
    }

    //chama a funcao createTables
    createTables(db);
    
    //fecha a db
    sqlite3_close(db);
    return 0;
}