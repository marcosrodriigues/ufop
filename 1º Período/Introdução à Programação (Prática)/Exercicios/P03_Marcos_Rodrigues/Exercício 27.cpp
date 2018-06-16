/*
	Criar um programa que leia um número (NUM) e então imprima os múltiplos de 3 e 5, ao mesmo tempo, no intervalo fechado de 1 a NUM. 
*/

#include <iostream>
using namespace std;

int main() {
	
	int NUM;
	bool temMultiplo = false;
	
	cout << "Entre com um numero: \n";
	cin >> NUM;
	
	if (NUM > 1) {
		for(int i = 1; i <= NUM; i++) {
			if ((i % 3 == 0) && (i % 5 == 0)) {
				cout << "O numero " << i << " eh multiplo de 3 e 5. \n";
				temMultiplo = true;
			}		
		}
		
		if(!temMultiplo)
			cout << "Nao existem multiplos de 3 e 5 no intervalo de 1 ate " << NUM << "\n";
	} else {
		cout << "Numero deve ser maior que zero.\n";
	}
	
		
	return 0;
}