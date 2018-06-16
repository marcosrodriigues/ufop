/*
	Criar um programa que imprima todos os números de 1 até 100, inclusive, e a soma do quadrado desses números.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int soma, i;
	for(i = 1; i <= 100; i++) { 
		cout << i << "\n";
		soma = soma + pow(i, 2);
	}
	
	cout << "Soma do quadrado dos numeros: " << soma;
		
	return 0;
}