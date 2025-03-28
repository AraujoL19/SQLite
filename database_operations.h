#ifndef DATABASE_OPERATIONS_H
#define DATABASE_OPERATIONS_H

#include <string>
#include "sqlite3.h"

//criação de tabelas
int createDB(const char* s);
int createInputTable(const char* s);
int createModelTable(const char* s);
int createOutputTable(const char* s);
int createSimulationTable(const char* s);

//inserção de dados
int insertInputData(const char* s, int inputId, const std::string& cortisolExpParams, 
                   char simulationGender, const std::string& initialConditions);
int insertModelData(const char* s, int modelId, const std::string& modelDescription, 
                   int modelVersion);
int insertOutputData(const char* s, int outputId, int modelId, int inputId, 
                    const std::string& results);
int insertSimulationData(const char* s, int simulationId, int outputId, 
                        int timeDays, const std::string& simulationStatus);
int insertGeneralData(const char* s);

#endif // DATABASE_OPERATIONS_H