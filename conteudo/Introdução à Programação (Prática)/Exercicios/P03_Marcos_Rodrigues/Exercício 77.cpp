/*
	Criar  um  programa  que  leia  vários  números  e  encerre a  leitura  com  0  e  imprima  o maior, o menor e a média aritmética dos números. 
	O número 0 (zero) não faz parte da seqüência.
*/
#include <iostream>
using namespace std;

int main() {
	int maiorNumero = -99999, menorNumero = 99999, numero, qtd = 0, soma = 0;
	double media = 0.0;
	
	cout << "Entre com um numero:\n";
	cin >> numero;
	
	while (numero != 0) {
		qtd++;
		
		if (numero > maiorNumero)
			maiorNumero = numero;
			
		if (numero < menorNumero)
			menorNumero = numero;
		
		soma = soma + numero;
		cout << "Entre com um numero:\n";
		cin >> numero;
	}
	media = (double)soma / qtd;
	
	cout << "Maior numero: " << maiorNumero << "\nMenor numero: " << menorNumero << "\nMedia: " << media;
	
	return 0;
}