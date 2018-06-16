#ifndef __BINARY_TREE_H_INCLUDED__
#define __BINARY_TREE_H_INCLUDED__

#include "TRegistro.h"

typedef struct{
	TRegistro registro;
	int esq, dir;
}TArvore;

void criaArvore(FILE* file, int amount, int *nTransfer, int *nCompare);
void pesquisaArvore(TRegistro *reg, int key, int *nTransfer, int *nCompare);

#endif
