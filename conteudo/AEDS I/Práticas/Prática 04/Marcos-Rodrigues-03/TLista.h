#include <string>
using namespace std;

typedef struct Item {
	string nome;
}TItem;

typedef struct Celula {
	struct Celula *pProx;
	TItem item;
}TCelula;

typedef struct Lista {
	TCelula *pPrimeiro, *pUltimo;
}TLista;

void TLista_Inicia(TLista *lista);
int TLista_EhVazia(TLista *lista);
int TLista_Insere(TLista *lista, TItem item);
int TLista_RetiraPrimeiro(TLista *lista, TItem *item);
int TLista_Concaternar (TLista *lista, TLista *list);
int TLista_Pesquisar (TLista lista, TItem *item);
int TLista_Exibir(TLista lista);