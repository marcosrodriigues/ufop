#ifndef __TREGISTRO_H_INCLUDED__
#define __TREGISTRO_H_INCLUDED__

#include "Include.h"
//Definição de um item do arquivo de dados
typedef struct {
	int chave;
	long dado1;
	char dado2[500];
}TRegistro;

#endif
