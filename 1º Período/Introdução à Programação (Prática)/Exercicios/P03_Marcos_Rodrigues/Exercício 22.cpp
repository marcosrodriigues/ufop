/*
	Criar um programa que leia um número (NUM), e depois leia NUM números inteiros e imprima o maior deles
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int NUM, NUM2, maiorNUM;
	maiorNUM = 0;
	
	cout << "Entre com um numero: \n";
	cin >> NUM;
	
	for(int i = 0; i < NUM; i++) {
		cout << "Digite o " << (i + 1) << ". numero: \n";
		cin >> NUM2;
		
		if (NUM2 > maiorNUM)
			maiorNUM = NUM2;
	}
	
	cout << "Maior numero lido: " << maiorNUM;
		
	return 0;
}