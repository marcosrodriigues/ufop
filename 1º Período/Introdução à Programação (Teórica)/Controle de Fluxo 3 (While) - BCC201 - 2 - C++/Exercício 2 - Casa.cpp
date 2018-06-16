/*
	Marcos Rodrigues
	2014.2.4341
	Introdução à Programação
*/
#include <iostream>
using namespace std;

int main() {
	
	int numero;
	
	cout << "Digite um numero qualquer: \n";
	cin >> numero;
	
	for (int i = 0; i <= 10; i++) {
		cout << i << " x " << numero << " = " << (i * numero) << "\n";
	}
	
	return 0;
}