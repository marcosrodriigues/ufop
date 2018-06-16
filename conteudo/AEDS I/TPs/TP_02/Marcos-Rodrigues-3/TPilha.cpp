#include "TPilha.h"
#include <iostream>
using namespace std;

void TPilha_New (TPilha *pilha) {
	pilha->primeiro = INICIO;
	pilha->ultimo = pilha->primeiro;
}

int TPilha_Empty(TPilha *pilha) {
	return (pilha->primeiro == pilha->ultimo ? 1 : 0);
}

int TPilha_Push(TPilha *pilha, int elem) {
	if (pilha->ultimo == MAXIMO) {
		return 0;
	}
	
 	TItem item;
	item.number = elem;
	pilha->item[pilha->ultimo++] = item;
	return 1;
}

int TPilha_Pop(TPilha *pilha, TItem *item) {
	if (TPilha_Empty(pilha)) {
		return 0;
	}

	*item = pilha->item[pilha->ultimo - 1];
	pilha->ultimo = pilha->ultimo--;
	return 1;
}

void TPilha_OrganizeWithQuickSort(TItem *itens, int n) {
	TPilha pilha_dir, pilha_esq;
	int esq, dir, i, j;
	TItem itemAux;

	TPilha_New(&pilha_dir);
	TPilha_New(&pilha_esq);
	esq = 0;
	dir = n - 1;

	TPilha_Push(&pilha_dir, dir);
	TPilha_Push(&pilha_esq, esq);

	do {
		if (dir > esq) {
			QuickSort_particion(itens, esq, dir, &i, &j);
			TPilha_Push(&pilha_dir, j);
			TPilha_Push(&pilha_esq, esq);
			esq = i;
		} else {
			TPilha_Pop(&pilha_dir, &itemAux);
			dir = itemAux.number;
			TPilha_Pop(&pilha_esq, &itemAux);
			esq = itemAux.number;
		}
	} while (!TPilha_Empty(&pilha_dir));	
}

void QuickSort_particion(TItem *itens, int esq, int dir, int *i, int *j) {
	TItem pivo, aux;
	*i = esq;
	*j = dir;
	pivo = itens[(*i + *j) / 2]; //get the X's pivo

	do {
		while (!(pivo.number <= itens[*i].number)) (*i)++;
		while (pivo.number < itens[*j].number) (*j)--;

		if (*i <= *j) {
			aux = itens[*i];
			itens[*i] = itens[*j];
			itens[*j] = aux;
			(*i)++; (*j)--;
		}
	} while (*i < *j);
}