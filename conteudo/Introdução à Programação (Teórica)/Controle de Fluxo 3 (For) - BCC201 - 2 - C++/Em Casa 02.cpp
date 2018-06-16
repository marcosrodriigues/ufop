/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Controle de Fluxo 3 (For) - Exercicio em casa - 02
*/

#include <iostream>
using namespace std;

int main() {
	int N;
	
	do {
		cout << "Digite o valor de N: ";
		cin >> N;
	} while (N < 0);
	
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			if (((i == 0) || ((i + 1) == N) || (k == 0) || ((k + 1) == N))) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}