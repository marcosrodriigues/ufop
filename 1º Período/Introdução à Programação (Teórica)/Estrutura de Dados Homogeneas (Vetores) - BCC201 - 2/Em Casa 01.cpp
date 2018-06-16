/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Vetores I - Exercicio em Casa - 01
*/

#include <iostream>
#include <limits.h>
using namespace std;

int main() {

	int num[6], maior = INT_MIN, menor = INT_MAX, count = 0;
	
	for(int i = 0; i < 6; i++) {
		cout << "Digite o " << (i + 1) << ". numero: ";
		cin >> num[i];
		cout << "\n";
		
		if (num[i] <= menor) menor = num[i];
		if (num[i] >= maior) maior = num[i];
		
		if(i == 0) {
			continue;
		}
		
		if (num[i] == num[0]) count++;
		
	}

	cout << "Maior numero lido:" << maior << ".\nMenor numero lido: " << menor << "\nNumeros iguals ao primeiro: " << count;
	
	return 0;
}