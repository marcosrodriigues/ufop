/*
	Marcos Rodrigues
	2014.2.4341
	Introdução à Programação
*/

#include <iostream>
#include <limits.h>
using namespace std;

int main () {
	int qtdPar = 0, qtdImpar = 0, menorPar = INT_MAX, maiorImpar = 0, numero;
	
	cout << "Digite um numero: \n";
	cin >> numero;
	
	while (numero != 0) {
		if (numero > 0) {
			if (numero % 2 == 0) {
				qtdPar++;
				if (numero < menorPar) {
					menorPar = numero;
				}
			} else {
				qtdImpar++;
				if(numero > maiorImpar) {
					maiorImpar = numero;
				}
			}
		}
		
		cout << "Digite um numero: \n";
		cin >> numero;
	}
	
	cout << "Quantidade de numeros pares: " << qtdPar << ".\n";
	cout << "Quantidade de numeros impares: " << qtdImpar << ".\n";
	cout << "Menor numero par: " << menorPar << ".\n";
	cout << "Maior numero impar: " << maiorImpar << ".\n";
	
	return 0;
}