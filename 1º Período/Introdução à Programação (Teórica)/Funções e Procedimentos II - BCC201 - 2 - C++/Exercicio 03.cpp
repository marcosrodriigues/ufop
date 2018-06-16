/*
	Marcos Rodrigues - 14.2.4341
	Introdução à Programação
	Funções II - Exercício 03.cpp
*/

#include <iostream>
using namespace std;

int fibonacci(int total) {
	int n0 = 1, n1 = 1, nProx = 0;
	
	if (total == 1)
		cout << n0;
	else if (total == 2)
		cout << n0 << "," << n1;
	else {
	
		cout << n0 << "," << n1 << ",";
		for(int i = 1; i <= total-2; i++) {
			nProx = n0 + n1;
			n0 = n1;
			n1 = nProx;
			cout << nProx;
			
			if (i != (total - 2)) {
				cout << ",";
			}
		}
	}
	
	
	
}

int main() {
	
	int total;
	
	cout << "Digite quantos numeros da sequencia deseja: \n";
	cin >> total;	
	
	fibonacci(total);

	return 0;
}