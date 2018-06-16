/*
	Marcos Rodrigues - 14.2.4341
	Introdução à Programação
	Funções II - Exercício 02.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

int numPar(int vet[]) {
	int countPar = 0;
	for(int i = 0; i < sizeof(vet); i++) {
		if (vet[i] % 2 == 0) {
			countPar++;
		}
	}
	
	return countPar;
}

int main() {
	
	int total, count;
	
	do {
		cout << "Digite o total de valores: \n";
		cin >> total;
	} while (total <= 0);
	
	int vetor[total];
	
	for (int i = 0; i < total; i++) {
		cout << "Digite o " << (i + 1) << ". valor: ";
		cin >> vetor[i];
		cout << "\n";
	}
	
	count = numPar(vetor);
	
	cout << "Total de numeros pares: " << count << endl;

	return 0;
}