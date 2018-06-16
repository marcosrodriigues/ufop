#include <iostream>
#include <stdlib.h>
#include "TLista.h"
using namespace std;


void TLista_Inicia(TLista *lista) {
	lista->pPrimeiro = (TCelula*) malloc(sizeof(TCelula));
	lista->pUltimo = lista->pPrimeiro;
	lista->pPrimeiro->pProx = NULL;
}

int TLista_EhVazia(TLista *lista) {
	return (lista->pPrimeiro == lista->pUltimo ? 1 : 0 );
}

int TLista_Insere(TLista *lista, TItem item) {
	lista->pUltimo->pProx = new TCelula;
	lista->pUltimo = lista->pUltimo->pProx;
	lista->pUltimo->item = item;
	lista->pUltimo->pProx = NULL;
	return 1;
}

int TLista_RetiraPrimeiro(TLista *lista, TItem *item) {
	if (TLista_EhVazia(lista))
		return 0;
	
	TCelula *pAux;
	pAux = lista->pPrimeiro->pProx;
	*item = pAux->item;
	lista->pPrimeiro->pProx = pAux->pProx;
	delete pAux;
	return 1;
}

int TLista_Concaternar (TLista *lista, TLista *list) {
	if (TLista_EhVazia(list))
		return 0;
	
	lista->pUltimo->pProx = list->pPrimeiro->pProx;
	return 1;
}

int TLista_Pesquisar (TLista lista, TItem *item) {
	if (TLista_EhVazia(&lista))
		return 0;
	
	int count = 0;
	TCelula *cel = lista.pPrimeiro->pProx;
	
	while (lista.pPrimeiro->pProx != NULL) {
		count++;
		if (lista.pPrimeiro->pProx->item.nome == item->nome) {
			cout << "Item encontrado na posicao " << count << "." << endl;
			return 1;
		}
		lista.pPrimeiro->pProx = (lista.pPrimeiro->pProx->pProx == NULL ? NULL : lista.pPrimeiro->pProx->pProx);
	}
	
	cout << "Nenhum item encontrado." << endl;
	lista.pPrimeiro->pProx = cel;
	
	return 1;
}

int TLista_Exibir(TLista lista) {
	if (TLista_EhVazia(&lista))
		return 0;
	
	TCelula *cel = lista.pPrimeiro->pProx;
	
	while (lista.pPrimeiro->pProx != NULL) {
		cout << lista.pPrimeiro->pProx->item.nome << endl;
		lista.pPrimeiro->pProx = (lista.pPrimeiro->pProx->pProx == NULL ? NULL : lista.pPrimeiro->pProx->pProx);
	}
	
	lista.pPrimeiro->pProx = cel;
}