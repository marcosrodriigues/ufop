#include "TLista.h"
#include <iostream>
using namespace std;

void TLista_New (TLista *lista) {
	lista->primeiro = INICIO;
	lista->ultimo = lista->primeiro;
}

bool TLista_Empty (TLista *lista) {
	return (lista->primeiro == lista->ultimo ? true : false);
}

void TLista_Insert (TLista *lista, TItem item) {
	if (lista->ultimo == MAXIMO - 1)
		return;

	lista->item[lista->ultimo++] = item;
}

void TLista_Organize(TLista *lista) {
	string strAux;
	int intAux;

	int countString = -1, countInt = -1;

	for (int i = 0; i < lista->ultimo; ++i) {

		countString = -1; countInt = -1;

		if (lista->item[i].isNumber) countInt = i;
		else countString = i; 

		for (int j = i + 1; j < lista->ultimo; ++j) {
			//Se for numero na lista na posicao J e na posicao I, compara
			if (lista->item[j].isNumber && countInt == i) {
				if(lista->item[countInt].number > lista->item[j].number) {
					intAux = lista->item[j].number;
					lista->item[j].number = lista->item[countInt].number;
					lista->item[countInt].number = intAux;
				}
			} else if (!(lista->item[j].isNumber) && (countString == i)) {
				if(strToLower(lista->item[countString].str) > strToLower(lista->item[j].str)) {
					strAux = lista->item[j].str;
					lista->item[j].str = lista->item[countString].str;
					lista->item[countString].str = strAux;
				}
			}
		}
	}
}

void TLista_View (TLista *lista) {
	int cString = 0, cInt = 0;
	for (int i = 0; i < lista->ultimo; ++i) {
		
		if (lista->item[i].isNumber)
			cout << lista->item[i].number;
		else
			cout << lista->item[i].str;

		if (i != lista->ultimo - 1) cout << ", ";
	}

	cout << "." << endl;
}

bool isNumber (string line) {
    return (atoi(line.c_str())); 
}

int stoi (string line) {
    return (atoi(line.c_str())); 
}

string strToLower(string str) {
	string converted;

	for(int i = 0; i < str.size(); ++i)
		converted += tolower(str[i]);
	
	//cout << "lowercase: " << converted << endl;
	return converted;
}