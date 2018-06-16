#include <iostream>
#include <stdlib.h>
#include "TLista.h"
using namespace std;


void TLista_Inicia(TLista *lista) {
	lista->pPrimeiro = NULL;
	lista->pUltimo = NULL;
}

int TLista_EhVazia(TLista *lista) {
	return (lista->pPrimeiro == NULL ? 1 : 0 );
}

int TLista_Insere(TLista *lista, TItem item) {
	TCelula *novo = new TCelula;
	novo->item = item;
	novo->pProx = NULL;
	
	if (TLista_EhVazia(lista)) {
		lista->pPrimeiro = novo;
		lista->pUltimo = novo;
	} else {
		lista->pUltimo->pProx = novo;
		lista->pUltimo = novo;		
	}
	
	return 1;
}

int TLista_RetiraPrimeiro(TLista *lista, TItem *item) {
	if (TLista_EhVazia(lista))
		return 0;
	
	TCelula *pAux;
	pAux = lista->pPrimeiro;
	*item = pAux->item;
	lista->pPrimeiro = pAux->pProx;
	delete pAux;
	return 1;
}

int TLista_Concaternar (TLista *lista, TLista *list) {
	if (TLista_EhVazia(list))
		return 0;
		
	if (TLista_EhVazia(lista)) {
		lista->pPrimeiro = list->pPrimeiro;
	} else {
		lista->pUltimo->pProx = list->pPrimeiro;
	}
	
	lista->pUltimo = list->pUltimo;		
	
	return 1;
}

int TLista_Pesquisar (TLista lista, TItem *item) {
	if (TLista_EhVazia(&lista))
		return 0;
	
	int count = 0;
	TCelula *cel = lista.pPrimeiro;
	
	while (lista.pPrimeiro != NULL) {
		if (lista.pPrimeiro->item.nome == item->nome) {
			cout << "Item encontrado na posicao " << count << "." << endl;
			return 1;
		}
		count++;
		lista.pPrimeiro = (lista.pPrimeiro->pProx == NULL ? NULL : lista.pPrimeiro->pProx);
	}
	
	cout << "Nenhum item encontrado." << endl;
	lista.pPrimeiro = cel;
	
	return 1;
}

int TLista_Exibir(TLista lista) {
	if (TLista_EhVazia(&lista))
		return 0;
	
	TCelula *cel = lista.pPrimeiro;
	
	while (lista.pPrimeiro != NULL) {
		cout << lista.pPrimeiro->item.nome << endl;
		lista.pPrimeiro = (lista.pPrimeiro->pProx == NULL ? NULL : lista.pPrimeiro->pProx);
	}
	
	lista.pPrimeiro = cel;
}