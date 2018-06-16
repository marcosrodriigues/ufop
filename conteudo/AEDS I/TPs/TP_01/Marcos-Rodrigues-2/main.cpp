#include <iostream>
#include "Album.h"

int main() {
	TLista *lista = new TLista;
	TAlbum *album;
	TArtista *artista = new TArtista;
	
	string nomeArtista, nomeAlbum, generoMusica;
	int anoLancamento;

	iniciarLista(lista);
	
	for(int i = 0; i < 10; i++) {
		getline(cin, nomeArtista);
		getline(cin, nomeAlbum);
		cin >> anoLancamento;
		cin.ignore();
		getline(cin, generoMusica);
		
		artista = newArtista(artista, nomeArtista);
		album = newAlbum(album, generoMusica, nomeAlbum, anoLancamento, *artista);
		
		insereLista(lista, *album);
	}

	organizarLista(lista);
	imprimirLista(lista);
	return 0;
}