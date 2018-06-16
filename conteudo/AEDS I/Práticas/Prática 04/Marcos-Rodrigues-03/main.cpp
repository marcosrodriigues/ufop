#include "TLista.h"
#include <iostream>
using namespace std;

int main () {
	
	TLista *lista = new TLista;
	TLista *lista2 = new TLista;
	int op;
	
	TLista_Inicia(lista);
	TLista_Inicia(lista2);

	TItem *x = new TItem;
	int opAux;
	
	do {
		cout << "1 - Inserir na lista 1. " << endl;
		cout << "2 - Remover na lista 1. " << endl;
		cout << "3 - Pesquisar na lista 1. " << endl;
		cout << "4 - Inserir na lista 2. " << endl;
		cout << "5 - Remover na lista 2. " << endl;
		cout << "6 - Pesquisar na lista 2. " << endl;
		cout << "7 - Concaternar duas listas. " << endl;
		cout << "8 - Exibir lista 1. " << endl;
		cout << "9 - Exibir lista 2. " << endl;
		cout << "0 - Sair" << endl;
		
		cin >> op;
		cin.ignore();
		
		switch(op) {
			cout << "op: " << op << endl;
			case 1:
				cout << "Digite o nome que ira salvar na lista 1: ";
				getline(cin, x->nome);
				TLista_Insere(lista, *x);
				break;
			case 2:
				TLista_RetiraPrimeiro(lista, x);
				break;
			case 3:
				cout << "Digite o nome que ira buscar na lista 1: ";
				getline(cin, x->nome);
				TLista_Pesquisar(*lista, x);
				break;
			case 4:
				cout << "Digite o nome que ira salvar na lista 2: ";
				getline(cin, x->nome);
				TLista_Insere(lista2, *x);
				break;
			case 5:
				TLista_RetiraPrimeiro(lista2, x);
				break;
			case 6:
				cout << "Digite o nome que ira buscar na lista 2: ";
				getline(cin, x->nome);
				TLista_Pesquisar(*lista2, x);
				break;
			case 7:
				TLista_Concaternar(lista, lista2);
				break;	
			case 8:
				TLista_Exibir(*lista);
				break;	
			case 9:
				TLista_Exibir(*lista2);
				break;	
		}
		
	} while (op != 0);
	
	return 0;
}