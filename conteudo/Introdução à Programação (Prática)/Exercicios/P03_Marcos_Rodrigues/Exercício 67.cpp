/*
	Construa  um  programa  para  fazer  a  soma  de  vários  valores  inteiros  e  positivos, fornecidos pelo usuário através do teclado.
	O dado que finaliza a seqüência de entrada é o número –1, e este não deve ser considerado.
*/
#include <iostream>
using namespace std;

int main() {
	int soma = 0, valor;
	
	cout << "Digite um valor: \n";
	cin >> valor;
	
	while (valor != -1) {
		//Somente numeros inteiros e positivos.
		if (valor >= 0) {
			soma = soma + valor;
		}
		
		cout << "Digite um valor: \n";
		cin >> valor;
	}
	
	cout << "A soma dos valores inteiros e positivos eh: " << soma << "\n";
	return 0;
}