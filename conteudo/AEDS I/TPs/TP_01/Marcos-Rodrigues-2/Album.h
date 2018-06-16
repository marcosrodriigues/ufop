#include "Artista.h"
#define INICIO 0
#define TAMMAX 10
using namespace std;

typedef struct Album {
	string genero, nomeAlbum;
	TArtista artista;
	int ano;
}TAlbum;

typedef struct Lista {
	TAlbum album[TAMMAX];
	int primeiro, ultimo;
}TLista;

TAlbum* newAlbum(TAlbum *album, string genero, string nomeAlbum, int ano, TArtista artista);
void iniciarLista(TLista *lista);
bool listaVazia(TLista *lista);
void insereLista(TLista *lista, TAlbum album);
void imprimirLista(TLista *lista);
void organizarLista(TLista *lista);