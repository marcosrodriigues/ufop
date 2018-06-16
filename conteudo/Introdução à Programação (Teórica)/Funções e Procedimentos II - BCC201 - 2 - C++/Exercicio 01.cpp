/*
	Marcos Rodrigues - 14.2.4341
	Introdução à Programação
	Funções II - Exercício 01.cpp
*/

#include <iostream>
#include <cmath>
using namespace std;

void quadrado(int num1, int num2) {
	if (num1 > num2) {
		for (int i = num2; i <= num1; i++) {
			cout << i << ". elevado ao quadrado: " << pow(i, 2) << endl;
		}
	} else {
		for (int i = num1; i <= num2; i++) {
			cout << i << ". elevado ao quadrado: " << pow(i, 2) << endl;
		}
	}
}

int main() {
	int n1, n2;
	
	cout << "Digite dois numeros: \n";
	cin >> n1 >> n2;
	
	quadrado(n1, n2);

	return 0;
}