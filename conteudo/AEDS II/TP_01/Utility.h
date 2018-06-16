#ifndef __UTILITY_H_INCLUDED__
#define __UTILITY_H_INCLUDED__

#include "Include.h"
#include "TRegistro.h"

#define ORDEM_ASCE 			1
#define ORDEM_DESC 			2
#define ORDEM_RAND 			3

#define SEQUENTIAL_INDEX	1
#define BINARY_TREE		 	2
#define B_TREE           	3
#define B_STAR_TREE		   	4

#define MIN_REGISTER 10
#define MAX_REGISTER 1000000
#define FILE_EXT ".bin"
#define FILE_NAME "REGISTRO_"

FILE* chooseFile(int situation);
bool argumentsOk(int argc, char const *argv[]);
double getTimeExecution(clock_t end, clock_t start);
void showInfo(TRegistro reg, int nTransfer, int nCompare, double middle_search, double middle_mount, FILE* arqSaida);

#endif
