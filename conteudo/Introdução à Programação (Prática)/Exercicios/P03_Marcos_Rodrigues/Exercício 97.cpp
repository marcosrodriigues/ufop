/*
	Escreva um programa que receba o número da conta e o saldo de várias pessoas. 
	O programa deve imprimir todas as contas, os respectivos saldos e uma das mensagens: positivo/negativo. 
	Ao final, o percentual de pessoas com saldo negativo. 
	O programa acaba quando se digita um número negativo para a conta. 
*/
#include <iostream>
using namespace std;

int main() {
	int numConta, count = 0, countNegativo = 0;
	double saldo, percentualNegativo = 0.0;
	
	cout << "Digite o numero da conta: \n";
	cin >> numConta;
	
	while (numConta >= 0) {
		count++;
		
		cout << "Digite o saldo da conta: \n";
		cin >> saldo;	
		
		cout << "Conta: " << numConta << "; Saldo: " << saldo << "; ";
		if (saldo < 0.0) {
			countNegativo++;
			cout << "Negativo\n\n";
		} else {
			cout << "Positivo\n\n";
		}		
		
		cout << "Digite o numero da conta: \n";
		cin >> numConta;	
	}
	
	percentualNegativo = ((double)countNegativo / count) * 100;
	
	cout << "\nO percentual de pessoas com saldo negativo eh: " << percentualNegativo << "%";
	
	return 0;
}