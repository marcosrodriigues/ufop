/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Vetores I - Exercicio em Casa - 02
*/

#include <iostream>
using namespace std;

int main() {

	const int MAX = 10;
	int N;
	
	do {
		cout << "Digite o tamanho dos vetores: ";
		cin >> N;
	} while (N <= 0 && N > MAX);
	
	int vetA[N], vetB[N];
	
	for (int i = 0; i < N; i++) {
		cout << "Digite o valor do " << (i + 1) << ". numero: ";
		cin >> vetA[i];
	}
	
	for (int i = 0; i < N; i++) {
		for(int k = 0; k < N; k++) {
			if (vetA[k] % 2 == 0) {
				vetB[i] = vetA[k];
				i++;
			}
		}
		
		for(int k = 0; k < N; k++) {
			if (vetA[k] % 2 != 0) {
				vetB[i] = vetA[k];
				i++;
			}
		}
	}
	
	cout << "Vetor B: \n";
	
	for(int i = 0; i < N; i++) {
		cout << vetB[i] << " ";
	}
	
	return 0;
}