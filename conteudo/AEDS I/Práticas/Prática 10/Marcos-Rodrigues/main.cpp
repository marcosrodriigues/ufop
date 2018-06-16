#include "THash.h"
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
	
	TArvore *raiz = new TArvore;
	THash *hash;
	TDicionario dic;

	//Arvore
	TArvore_Inicia(raiz);

	//Hash
	hash = THash_Inicia(MAX_LISTA_ENCADEADA, MAX_PESOS_ENCADEADA);

	//Encademaento aberto
	TDicionario_Inicia(dic);

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
			TArvore_Insere(raiz, contact);
			Insere(raiz, &contact);
			THash_Insere(hash, contact);
			TDicionario_Insere(dic, contact);
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

			totalCompare = 0;
			contAux = TArvore_Pesquisa(*(raiz), phoneAux, &contact, &totalCompare);

			cout << "Arvore Binaria" << endl;
			if (contAux == 1) {
				cout << contact.name << " ";
				cout << setw(4) << setfill('0') << contact.birthday << " ";
				cout << "1" << " ";
				cout << totalCompare << endl;
			} else {
				cout << "Nao encontrado" << " " << "-1" << " " << totalCompare << endl;
			}

			totalCompare = 0;
			contAux = TArvore_Pesquisa(*(raiz), phoneAux, &contact, &totalCompare);

			cout << "Arvore AVL" << endl;
			if (contAux == 1) {
				cout << contact.name << " ";
				cout << setw(4) << setfill('0') << contact.birthday << " ";
				cout << "1" << " ";
				cout << totalCompare << endl;
			} else {
				cout << "Nao encontrado" << " " << "-1" << " " << totalCompare << endl;
			}

			totalCompare = 0;
			contAux = THash_Pesquisa(hash, phoneAux, &contact, &totalCompare);

			cout << "Hash Encadeada" << endl;
			if (contAux == 1) {
				cout << contact.name << " ";
				cout << setw(4) << setfill('0') << contact.birthday << " ";
				cout << "1" << " ";
				cout << totalCompare << endl;
			} else {
				cout << "Nao encontrado" << " " << "-1" << " " << totalCompare << endl;
			}

			totalCompare = 0;
			contAux = TDicionario_Pesquisa(dic, phoneAux, &totalCompare);

			cout << "Hash Aberta " << endl;
			if (contAux != -1) {
				cout << contact.name << " ";
				cout << setw(4) << setfill('0') << contact.birthday << " ";
				cout << "1" << " ";
				cout << totalCompare << endl;
			} else {
				cout << "Nao encontrado" << " " << "-1" << " " << totalCompare << endl;
			}

			cout << endl;

		}

		delete[] dict;
	}

	return 0;
}