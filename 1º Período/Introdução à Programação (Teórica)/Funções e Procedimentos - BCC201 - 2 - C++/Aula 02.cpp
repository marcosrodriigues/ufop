/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Função - Exercício Em Aula - 02
*/

#include <iostream>
using namespace std;

void linha(int li) {

	switch(li) {
		case 1:
			cout << "*****************" << endl;
			break;
		case 2:
			cout << "Anita Lopes" << endl;
			break;
		case 3:
			cout << "=================" << endl;
			break;
		case 4:
			cout << "Guto Garcia" << endl;
			break;
		case 5:
			cout << "#################" << endl;
			break;
	}
}

int main() {

	int l;
	do {
		cout << "Digite o numero da linha (de 1 a 5): ";
		cin >> l;
	} while (l < 1 || l > 5);
	
	linha(l);
	return 0;
}