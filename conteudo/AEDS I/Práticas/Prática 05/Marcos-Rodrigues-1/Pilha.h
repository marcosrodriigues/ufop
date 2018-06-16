#include <string>
using namespace std;

typedef struct Item {
	int numero;
	char op;
}TItem;

typedef struct Celula {
	struct Celula *pProx;
	TItem item;
}TCelula;

typedef struct Pilha {
	TCelula *pPrimeiro, *pUltimo;
	int count;
}TPilha;

void TPilha_Inicia(TPilha *pilha);
int TPilha_EhVazia(TPilha *pilha);
int TPilha_Push(TPilha *pilha, TItem item);
int TPilha_Pop(TPilha *pilha, TItem *item);
int TPilha_Tamanho (TPilha *pilha);
void TPilha_Limpa (TPilha *pilha);
