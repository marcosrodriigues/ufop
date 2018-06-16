/*
	Escreva um programa que receba vários números, e finalize com a entrada do número –999. 
	Para cada número, o programa deve imprimir seus divisores. 
*/
#include <iostream>
using namespace std;

int main() {
	int num;
	
	cout << "Digite um numero: \n";
	cin >> num;
	
	while (num != -999) {
		
		/*
			Não sei se era pra mostrar os números inteiros e positivos, mas coloquei com o I começando no 1, pois se fosse usar os numeros negativos,
			o for ia rodar MUITAS VEZES, e poderia perder desempenho, rodando entre todos os numeros.
		*/
		
		for(int i = 1; i <= num; i++) {
			if (num % i == 0) {
				cout << "O numero " << i << " eh divisor de " << num << "\n";
			}
		}
		
		cout << "\nDigite um numero: \n";
		cin >> num;
	}
	
	return 0;
}