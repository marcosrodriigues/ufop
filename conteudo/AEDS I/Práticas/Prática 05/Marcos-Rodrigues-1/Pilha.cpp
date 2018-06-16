#include <stdlib.h>
#include <iostream>
#include "Pilha.h"
using namespace std;

void TPilha_Inicia(TPilha *pilha) {
	pilha->pPrimeiro = NULL;
	pilha->pUltimo = NULL;
}

int TPilha_EhVazia(TPilha *pilha) {
	return (pilha->pPrimeiro == pilha->pUltimo ? 1 : 0 );
}

int TPilha_Push(TPilha *pilha, TItem item) {
	TCelula *aux = new TCelula;
	aux->item = item;
	aux->pProx = pilha->pPrimeiro;
	pilha->pPrimeiro = aux;
	pilha->count++;

	return 1;
}

int TPilha_Pop(TPilha *pilha, TItem *item) {
	if (TPilha_EhVazia(pilha))
		return 0;
	
	TCelula *pAux = pilha->pPrimeiro;
	pilha->pPrimeiro = pAux->pProx;
	*item = pAux->item;
	delete pAux;
	pilha->count--;
	
	return 1;
}

int TPilha_Tamanho (TPilha *pilha) {
	//cout << "Tamanho: " << pilha->count << endl;
	return pilha->count;	
}

void TPilha_Limpa (TPilha *pilha) {
	pilha->pPrimeiro = NULL;
	pilha->pUltimo = NULL;
	pilha->count = 0;
}