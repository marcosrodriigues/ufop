#include <string>
#include <stdlib.h>
#define INICIO 0
#define MAXIMO 1000
using namespace std;

typedef struct Item {
	string str;
	int number;
	bool isNumber;
}TItem;

typedef struct Lista {
	TItem item[MAXIMO];
	int primeiro, ultimo;
}TLista;

void TLista_New (TLista *lista);
bool TLista_Empty (TLista *lista);
void TLista_Insert (TLista *lista, TItem item);
void TLista_Organize(TLista *lista);
void TLista_View (TLista *lista);
bool isNumber (string line);
int stoi (string line);
string strToLower(string str);