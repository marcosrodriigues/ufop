#include "Pilha.h"
#include <iostream>
#include <climits>
#include <cctype>
#include <stdlib.h>
using namespace std;

int main () {
	TPilha *pilha = new TPilha;
	TItem *item = new TItem;
	
	TItem *item_1 = new TItem;
	TItem *item_2 = new TItem;
	
	char val;
	int valAux;

	TPilha_Inicia(pilha);

	cin >> val;

	while (val != ';') {
		if (isdigit(val)) {
			item->numero = atoi(&val);
			TPilha_Push(pilha, *item);
		} else {			
			switch(val) {
				case '+':
					if (TPilha_Tamanho(pilha) >= 2) {
						TPilha_Pop(pilha, item_1);
						TPilha_Pop(pilha, item_2);
				
						valAux = item_2->numero + item_1->numero;
						item->numero = valAux;
						TPilha_Push(pilha, *item);
					}
					break;
				case '-':
					if (TPilha_Tamanho(pilha) >= 2) {
						TPilha_Pop(pilha, item_1);
						TPilha_Pop(pilha, item_2);
						
						valAux = item_2->numero - item_1->numero;
						item->numero = valAux;
						TPilha_Push(pilha, *item);
					}					
					break;
				case '*':
					if (TPilha_Tamanho(pilha) >= 2) {
						TPilha_Pop(pilha, item_1);
						TPilha_Pop(pilha, item_2);
						
						valAux = item_2->numero * item_1->numero;
						item->numero = valAux;
						TPilha_Push(pilha, *item);
					}
					break;
				case '/':
					if (TPilha_Tamanho(pilha) >= 2) {
						TPilha_Pop(pilha, item_1);
						TPilha_Pop(pilha, item_2);
						
						valAux = item_2->numero / item_1->numero;
						item->numero = valAux;
						TPilha_Push(pilha, *item);
					}
					break;
				case '=':
					if (TPilha_Tamanho(pilha) != 1) {
						cout << "Entrada Inconsistente." << endl;
						TPilha_Limpa(pilha);
						cin >> val;
						continue;
					}
					TPilha_Pop(pilha, item);
					cout << item->numero << endl;
					TPilha_Limpa(pilha);
					break;
			}
		}
		cin >> val;
	}

	return 0;
}
