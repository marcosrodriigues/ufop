/*
	Escreva um programa que realize a potência de A (número real) por B (número inteiro e positivo), ou seja, A^B, através de multiplicações sucessivas. 
	Esses dois  valores são passados pelo usuário através do teclado. 
*/

#include <iostream>
using namespace std;

int main() {
	
	double A, resultado;
	int B;
	
	cout << "Digite um numero real e outro numero inteiro: \n";
	cin >> A >> B;
	
	resultado = 1;
	if(B < 0) { 
		cout << "O segundo numero deve ser inteiro e positivo (maior que zero)";
		return 1;
	} else if (B == 0) {
		cout << "O valor do primeiro numero elevado ao segundo eh: 1";
	} else {
		for (int i = 0; i < B; i++) { 
			resultado = resultado * A;
		}
		
		cout << "O valor do primeiro numero elevado ao segundo eh: " << resultado;
	}
		
	return 0;
}