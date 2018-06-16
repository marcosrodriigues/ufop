#include "TContact.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() {

	int c, n, p;

	long phoneAux;
	int contAux;
	int totalCompare;

	TDictionary *dict;
	TContact contact;

	//cout << "Numero de casos: ";
	cin >> c;

	getchar();

	for (int i = 0; i < c; ++i) {
		//cout << "Numero de contatos: ";
		cin >> n;
		//cout << "Numero de pesquisas: ";
		cin >> p;

		dict = newDictionary(n);

		for (int i = 0; i < n; ++i) {
			//cout << "Digite o nome, aniversario (mmdd) e telefone do " << (i + 1) << " contato: " << endl;
			cin >> contact.name;
			cin >> contact.birthday;
			cin >> contact.phone;

			insertDictionary(dict, contact);
		}

		for (int i = 0; i < p; ++i) {
			cin >> phoneAux;	
			cout << phoneAux << endl;

			totalCompare = 0;
			contAux = searchSequential(dict, phoneAux, &totalCompare);

			if (contAux != -1) {
				cout << dict->contact[contAux].name << " ";
				cout << setw(4) << setfill('0') << dict->contact[contAux].birthday << " ";
				cout << contAux << " ";
				cout << totalCompare << endl;
			} else {
				cout << "Nao encontrado" << " " << contAux << " " << totalCompare << endl;
			}

			totalCompare = 0;
			contAux = searchBinary(dict, phoneAux, &totalCompare);

			if (contAux != -1) {
				cout << dict->contact[contAux].name << " ";
				cout << setw(4) << setfill('0') << dict->contact[contAux].birthday << " ";
				cout << contAux << " ";
				cout << totalCompare << endl;
			} else {
				cout << "Nao encontrado" << " " << contAux << " " << totalCompare << endl;
			}

			cout << endl;

		}

		delete[] dict;
	}

	return 0;
}