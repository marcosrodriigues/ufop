#ifndef INICIO
#define INICIO 0
#endif
#ifndef MAXIMO
#define MAXIMO 50
#endif

typedef struct Item {
	int number;
}TItem;

typedef struct Pilha{
	TItem item[MAXIMO];
	int primeiro, ultimo;
}TPilha;

int TPilha_Pop(TPilha *pilha, TItem *item);
int TPilha_Push(TPilha *pilha, int elem);
int TPilha_Empty(TPilha *pilha);
void TPilha_New(TPilha *pilha);
void TPilha_OrganizeWithQuickSort(TItem *itens, int n);
void QuickSort_particion(TItem *itens, int esq, int dir, int *i, int *j);