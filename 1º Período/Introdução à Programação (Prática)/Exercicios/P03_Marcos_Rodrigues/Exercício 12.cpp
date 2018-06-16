/*
	Escreva um programa que receba dez números do usuário e imprima o quadrado de cada número. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int number, i;
	for(i = 1; i <= 10; i++) { 
		cout << "Entre com o " << i << ". numero: ";
		cin >> number;
		
		cout << "\nQuadrado do " << i << ". numero: " << pow(number, 2);
		cout << "\n\n";
	}
		
	return 0;
}