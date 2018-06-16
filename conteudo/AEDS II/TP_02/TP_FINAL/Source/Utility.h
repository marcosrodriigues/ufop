#ifndef __UTILITY_H_INCLUDED__
#define __UTILITY_H_INCLUDED__

#include "Include.h"
#include "TRegistro.h"

#define ORDEM_ASCE 			1
#define ORDEM_DESC 			2
#define ORDEM_RAND 			3

#define INTERCALACAO_01		1
#define INTERCALACAO_02		2
#define QUICK_SORT		   	3

#define MIN_REGISTER 200
#define MAX_REGISTER 471705
#define FILE_EXT ".BIN"
#define FILE_NAME "PROVAO"

FILE* openFile();
char* nameFile();
bool argumentsOk(int argc, char const *argv[]);
double getTimeExecution(clock_t end, clock_t start);
void showInfo(TRegistro reg, int nTransfer, int nCompare, double middle_search, double middle_mount, FILE* arqSaida);

#endif
