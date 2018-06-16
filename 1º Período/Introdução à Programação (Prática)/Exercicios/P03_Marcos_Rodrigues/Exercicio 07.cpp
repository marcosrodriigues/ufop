/*
	Escreva um programa que imprima todos os números pares do intervalo fechado de 1 a 100.
*/

#include <iostream>
using namespace std;

int main() {
	
	for(int i = 1; i <= 100; i++) {
		if(i % 2 == 0)
			cout << i << "\n";
	}
	
	
	return 0;
}