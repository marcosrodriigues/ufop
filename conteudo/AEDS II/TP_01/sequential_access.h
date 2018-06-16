#ifndef __SEQUENTIAL_ACCESS_H_INCLUDED__
#define __SEQUENTIAL_ACCESS_H_INCLUDED__

#include "TRegistro.h"

#define ITENS_PAGINA 20
#define MAX_TABELA 50000

//Definição de uma entrada da tabela de índice das páginas
typedef struct {
	int posicao;
	int chave;
}TIndice;

/*	Funcao que irá realizar a busca sequencial no arquivo	*/
int Sequential_Search (TIndice tab[], int tam, TRegistro* dados, FILE *arq, int key, int *nTransfer, int *nCompare);
int fillUpTIndex(FILE *file, TIndice *tab, int amount);

#endif
