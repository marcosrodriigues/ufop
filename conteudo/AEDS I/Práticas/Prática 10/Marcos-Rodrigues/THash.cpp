#include "THash.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

//Inicio de Hash Encadeada
void TLista_Inicia(TLista *lista) {
	lista = new TLista;
	lista->pPrimeiro = NULL;
	lista->pUltimo = NULL;
}

int TLista_EhVazia(TLista *lista) {
	return (lista->pPrimeiro == NULL ? 1 : 0 );
}

int TLista_Insere(TLista *lista, TContact contact) {
	TCelula *novo = new TCelula;
	novo->contact = contact;
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

THash* THash_Inicia(int nLista, int nPesos) {
	THash *hash = new THash;

	int i;

	hash->n = 0;
	hash->nro_lista = nLista;
	hash->nro_pesos = nPesos;

	//inicializando as listas;
	hash->lista = new TLista[MAX_LISTA_ENCADEADA];
	for (int i = 0; i < MAX_LISTA_ENCADEADA; ++i)
		TLista_Inicia(&hash->lista[i]);

	hash->p = new int[MAX_PESOS_ENCADEADA];
	for (int i = 0; i < MAX_PESOS_ENCADEADA; ++i)
		hash->p[i] = rand() % 1000000;

	return hash;
}

int THash_H(THash *hash, long phone) {
	int i = 0;
	unsigned long soma = 0;

	while (phone != 0) {
		soma += (phone % 10) * (hash->p[i % hash->nro_pesos]); 
		phone = phone / 10;
		i++;
	}

	return (int)(soma % hash->nro_lista);
}

TCelula* THash_PesquisaCelula(THash *hash, long phone, int *totalCompare) {
	int i = THash_H(hash, phone);
	TCelula *aux;

	(*totalCompare)++;
	if (TLista_EhVazia(&hash->lista[i]))
		return NULL;
	aux = hash->lista[i].pPrimeiro;

	while((aux->pProx != NULL) && (phone != aux->contact.phone)) {
		(*totalCompare) = (*totalCompare) + 2;
		aux = aux->pProx;
	}
	(*totalCompare) = (*totalCompare) + 2;

	(*totalCompare)++;
	if (phone == aux->contact.phone) {
		return aux;
	}
	return NULL;
}

int THash_Pesquisa(THash *hash, long phone, TContact *contact, int *totalCompare) {
	TCelula *aux = THash_PesquisaCelula(hash, phone, totalCompare);
	(*totalCompare)++;
	if (aux == NULL)
		return 0;

	*contact = aux->contact;
	return 1;
}


int THash_Insere(THash *hash, TContact contact) {
	int x = 0;
	if (THash_PesquisaCelula(hash, contact.phone, &x) == NULL) {
		TLista_Insere(&hash->lista[THash_H(hash, contact.phone)], contact);
		hash->n++;
		return 1;
	}

	return 0;
}
//Fim de Hash Encadeada
//Hash com Enderecamento Aberto
void TDicionario_Inicia(TDicionario dic) {
	int i;
	for (int i = 0; i < MAX_LISTA_ABERTA; ++i)
		dic[i].phone = 0;

	return;
}

int TDicionario_H(TDicionario dic, long phone) {
	int i = 0;
	unsigned long soma = 0;
	int comp = phone;

	while (phone != 0) {
		soma += (phone % 10) * (i % MAX_PESOS_ABERTA); 
		phone = phone / 10;
		i++;
	}

	return (int)(soma % MAX_LISTA_ABERTA);
}

int TDicionario_Pesquisa(TDicionario dic, long phone, int *totalCompare) {
	int i = 0;
	int ini = TDicionario_H(dic, phone);

	while ((dic[(ini + i) % MAX_LISTA_ABERTA].phone != phone) && (dic[(ini + i) % MAX_LISTA_ABERTA].phone != 0) && i < MAX_LISTA_ABERTA) {
		(*totalCompare) = (*totalCompare) + 3;
		i++;
	}

	(*totalCompare) = (*totalCompare) + 3;

	(*totalCompare)++;
	if (dic[(ini + i) % MAX_LISTA_ABERTA].phone == phone)
		return (ini + i) % MAX_LISTA_ABERTA;

	return -1;
}

int TDicionario_Insere(TDicionario dic, TContact contact) {
	int x = 0;
	if (TDicionario_Pesquisa(dic, contact.phone, &x) >= 0)
		return 0;

	int i = 0;
	int ini = TDicionario_H(dic, contact.phone);

	while(dic[(ini + i) % MAX_LISTA_ABERTA].phone != 0 && i < MAX_LISTA_ABERTA)
		i++;

	if (i < MAX_LISTA_ABERTA) {
		dic[(ini + i) % MAX_LISTA_ABERTA] = contact;
		return 1;
	}

	return 0;
}