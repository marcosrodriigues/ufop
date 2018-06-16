#include <iostream>
#include "TFila.h"
using namespace std;

void TFila_New (TFila *fila) {
	fila->primeiro = INICIO;
	fila->ultimo = fila->primeiro;
}

bool TFila_Empty (TFila *fila) {
	return (fila->primeiro == fila->ultimo ? true : false);
}

void TFila_Push (TFila *fila, TFila *fila2, TItem item) {
	if (fila->ultimo == MAXIMO - 1)
		return;

	cout << "Filas atuais: " << endl;
	cout << "Fila 01: ";
	TFila_View(fila);
	cout << "Fila 02: ";
	TFila_View(fila2);
	cout << endl;

	TFila_Move_1_2(fila, fila2);

	cout << "Filas após movimentar a primeira fila pra segunda" << endl;
	cout << "Fila 01: ";
	TFila_View(fila);
	cout << "Fila 02: ";
	TFila_View(fila2);
	cout << endl;

	fila->item[fila->ultimo++] = item;

	cout << "Filas após adicionar o item  na Fila 1" << endl;
	cout << "Fila 01: ";
	TFila_View(fila);
	cout << "Fila 02: ";
	TFila_View(fila2);
	cout << endl;

	TFila_Move_2_1(fila2, fila);

	cout << "Filas após voltar com os itens da Segunda fila pra Primeira" << endl;
	cout << "Fila 01.:";
	TFila_View(fila);
	cout << "Fila 02.:";
	TFila_View(fila2);
	cout << endl;
}

int TFila_Pop (TFila *fila, TItem *item) {
	if (TFila_Empty(fila)) {
		return 0;
	}

	*item = fila->item[fila->ultimo];
	fila->ultimo = fila->ultimo - 1;
	return 1;
}

void TFila_View (TFila *fila) {
	if (TFila_Empty(fila)) {
		cout << "<vazia>" << endl;
		return;
	}

	for (int i = 0; i < fila->ultimo; ++i) {
		cout << fila->item[i].number << " ";
	}

	cout << endl;

	return;
}

void TFila_Move_1_2 (TFila *fromFila, TFila *toFila) {
	if (TFila_Empty(fromFila)) return;

	int countFila = 0;
	for (int i = 0; i < fromFila->ultimo; ++i) {
		toFila->ultimo++;		
		toFila->item[countFila].number = fromFila->item[i].number;

		countFila++;
	}

	fromFila->ultimo = 0;

	return;
}

void TFila_Move_2_1 (TFila *fromFila, TFila *toFila) {
	if (TFila_Empty(fromFila)) return;

	//valorDaPilha
	int valor = toFila->item[toFila->ultimo - 1].number;

	int countFila = 0;

	for (int i = 0; i < fromFila->ultimo; ++i) {
		toFila->ultimo++;		
		toFila->item[countFila].number = fromFila->item[i].number;

		countFila++;
	}

	fromFila->ultimo = 0;
	toFila->item[countFila].number = valor;

	return;
}