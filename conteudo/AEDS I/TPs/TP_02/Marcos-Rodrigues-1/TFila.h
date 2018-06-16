#define INICIO 0
#define MAXIMO 1000

typedef struct Item {
	int number;
}TItem;

typedef struct Fila {
	TItem item[MAXIMO];
	int primeiro, ultimo;
}TFila;

void TFila_New (TFila *fila);
bool TFila_Empty (TFila *fila);
void TFila_Push (TFila *fila, TFila *fila2, TItem item);
int TFila_Pop (TFila *fila, TItem *item);
void TFila_View (TFila *fila);
void TFila_Move_1_2 (TFila *fromFila, TFila *toFila);
void TFila_Move_2_1 (TFila *fromFila, TFila *toFila);
