/*
	Escreva um programa que receba números do usuário enquanto eles forem positivos e ao fim o programa deve imprimir quantos números foram digitados.
*/
#include <iostream>
using namespace std;

int main() {
	int numero, count = 0;
	
	cout << "Entre com um numero: \n";
	cin >> numero;
	
	while (numero >= 0) {
		count++;
		cout << "Entre com um numero: \n";
		cin >> numero;
	}
	
	/*
		Adicionando o "count++" aqui pois o exercício pede para imprimir a quantidade de numeros que foram digitados, 
		e não pede exclusividade para numeros negativos.
	*/
	count++;
	
	cout << "Foram digitados " << count << " numeros no total (positivos e negativos).";
		
	
	return 0;
}