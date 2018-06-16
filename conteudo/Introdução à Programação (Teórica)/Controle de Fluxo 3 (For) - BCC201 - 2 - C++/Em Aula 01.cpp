/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Controle de Fluxo 3 (For) - Exercicio em aula - 01
*/

#include <iostream>
using namespace std;

int main() {
	
	cout << " -- Combinação  -- \n\n";
	
	for(int i = 1; i <= 9; i++) {
		for(int j = 0; j < 10; j++) {
			cout <<  i << " e " << j << ".\n");
		}
		cout << "\n";
	}

	return 0;
}