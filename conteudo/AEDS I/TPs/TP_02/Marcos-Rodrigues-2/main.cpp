#include <iostream>
#include "TLista.h"
using namespace std;

int main() {
	TLista *lista = new TLista;
	TItem item;
	bool isFullList = false;

	string value;

	TLista_New(lista);


	getline(cin, value);

	for (int i = 0; i < value.size(); ++i) {
		if (value[i] == '.') {
			isFullList = true;
			break;
		}
	}

	if (isFullList) {
		string valAux;

		for (int i = 0; i < value.size(); ++i) {
			if (value[i] == '.' || value[i] == ',') {
				cout << "valorAux: " << valAux << endl;
				if (isNumber(valAux)) {
					item.isNumber = true;
					item.number = stoi(valAux);
				} else {
					item.isNumber = false;
					item.str = valAux;
				}

				TLista_Insert(lista, item);				

				valAux = "";

				if (value[i] == '.')
					break;

				i++;
			}
			valAux = valAux + value[i];
		}
	} else {
		while(value != ".") {
			if (isNumber(value)) {
				item.isNumber = true;
				item.number = stoi(value);
			} else {
				item.isNumber = false;
				item.str = value;
			}

			TLista_Insert(lista, item);

			getline(cin, value);
		}	
	}
	
	TLista_Organize(lista);
	TLista_View(lista);

	return 0;
}
