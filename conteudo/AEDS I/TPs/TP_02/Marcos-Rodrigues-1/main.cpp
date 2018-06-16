#include "TFila.h"
#include <iostream>
using namespace std;

int main() {
	
	TFila *fila = new TFila;
	TFila *fila2 = new TFila;
	TItem item;

	TFila_New(fila);
	TFila_New(fila2);

	int op, valor;

	cout << endl;
	cout << "1 - Push" << endl;
	cout << "2 - Pop" << endl;
	cout << "Qualquer outro valor o programa se encerrará" << endl << endl;
	cin >> op;
	while (op == 1 || op == 2) {
		switch(op) {
			case 1:
				cout << "Valor a ser inserido: ";
				cin >> valor;
				item.number = valor;

				TFila_Push(fila, fila2, item);
				break;
			case 2:
				TFila_Pop(fila, &item);

				cout << "Filas após um POP" << endl;
				cout << "Fila 01.:";
				TFila_View(fila);
				cout << "Fila 02.:";
				TFila_View(fila2);
				cout << endl;
				break;
		}

		cout << endl;
		cout << "1 - Push" << endl;
		cout << "2 - Pop" << endl;
		cout << "Qualquer outro valor o programa se encerrará" << endl << endl;
		cin >> op;
	}

	return 0;
}