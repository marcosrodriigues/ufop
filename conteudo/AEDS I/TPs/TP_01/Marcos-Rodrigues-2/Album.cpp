#include <string>
#include <iostream>
#include <stdlib.h>
#include "Album.h"
using namespace std;

TAlbum* newAlbum(TAlbum *album, string genero, string nomeAlbum, int ano, TArtista artista) {
	album = new TAlbum;
	
	album->genero = genero;
	album->nomeAlbum =nomeAlbum;
	album->ano = ano;
	album->artista = artista;
	
	return album;
}

void iniciarLista(TLista *lista) {
	lista->primeiro = INICIO;
	lista->ultimo = lista->primeiro;
}

bool listaVazia(TLista *lista) {
	return (lista->ultimo == lista->primeiro);
}

void insereLista(TLista *lista, TAlbum album) {
	if (lista->ultimo == TAMMAX)
		return;
	
	lista->album[lista->ultimo++] = album;
}

void organizarLista(TLista *lista) { 
	if (listaVazia(lista)) {
		return;
	}
	
	TAlbum aux;
	
	for (int i = INICIO; i < lista->ultimo; i++) {
		for (int j = i + 1; j < lista->ultimo; j++) {
			if (lista->album[i].ano >= lista->album[j].ano) {	
				aux = lista->album[i];
				lista->album[i] = lista->album[j];
				lista->album[j] = aux;
			}
		}
	}
}

void imprimirLista(TLista *lista) {
	if (listaVazia(lista)) {
		return;
	}
		
	for (int i = lista->primeiro; i < lista->ultimo; i++) {
		cout << lista->album[i].artista.nome << endl;
		cout << lista->album[i].nomeAlbum << endl;
		cout << lista->album[i].ano << endl;
		cout << lista->album[i].genero << endl << endl;
	}
}