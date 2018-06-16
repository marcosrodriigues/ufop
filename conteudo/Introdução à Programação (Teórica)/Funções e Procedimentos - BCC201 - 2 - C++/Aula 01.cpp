/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Função - Exercício Em Aula - 01
*/

#include <iostream>
using namespace std;

int Compara(double n1, double n2) {
	if (n1 == n2)
		return 1;
		
	return 0;
}

int main() {

	double number_1, number_2;
	
	cout << "Digite dois numeros reais: ";
	cin >> number_1 >> number_2;
	
	if(Compara(number_1, number_2) == 1)
		cout << "Os numeros sao iguais.";
	else
		cout << "Os numeros sao diferentes.";
	
	return 0;
}