#include <iostream>
#include "TLista.h"
using namespace std;


void TLista_FazVazia(TLista *lista) {
	lista->primeiro = INICIO;
	lista->ultimo = lista->primeiro;
}

int TLista_EhVazia(TLista *lista) {
	return (lista->primeiro == lista->ultimo ? 1 : 0);
}

int TLista_Insere(TLista *lista, TItem item) {
	if (lista->ultimo == MAXIMO)
		return 0;
	
	lista->item[lista->ultimo++] = item;
	return 1;
}

int TLista_Retira(TLista *lista, int p, TItem *item) {
	if (TLista_EhVazia(lista) || p >= lista->ultimo)
		return 0;
	
	item = &lista->item[p];
	lista->ultimo--;
	for (int i = p + 1; i < lista->ultimo; i++)
		lista->item[i-1] = lista->item[i];
	
	return 1;
}

int TLista_Concaternar (TLista *lista, TLista *list) {
	if (TLista_EhVazia(list))
		return 0;

	for (int i = 0; i < list->ultimo; i++)
		TLista_Insere(lista, list->item[i]);
	
	return 1;
}

int TLista_Pesquisar (TLista *lista, TItem *item) {
	if (TLista_EhVazia(lista))
		return 0;
		
	for (int i = 0; i < lista->ultimo; i++) {
		if (lista->item[i].nome == item->nome) {
			cout << "Item encontrado na posicao " << i << " do Array." << endl;
			return 1;
		}
	}
	
	cout << "Nenhum item encontrado." << endl;
	
	return 1;
}

int TLista_Exibir(TLista *lista) {
	if (TLista_EhVazia(lista))
		return 0;
	
	for (int i = 0; i < lista->ultimo; i++) {
		cout << lista->item[i].nome << endl;
	}
}