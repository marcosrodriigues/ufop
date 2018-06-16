#include <iostream>
#include "ContaBancaria.h"
using namespace std;

int main () {

	TContaBancaria *contaBancaria;
	int numConta, op, qtdContasTotal, qtdContasAbertas = 0;
	double valorGenerico;
	
	do {
		toWrite("Digite quantas contas deseja abrir: ");
		cin >> qtdContasTotal;
	} while (qtdContasTotal < 0);
	
	if (qtdContasTotal > 0) {
	
		contaBancaria = new TContaBancaria[qtdContasTotal];
	
		do {
			toWrite(" *** Digite a opcao que deseja: *** ");
			toWrite(" 1 -> Iniciar uma conta; ");
			toWrite(" 2 -> Depositar um valor; ");
			toWrite(" 3 -> Sacar um valor; ");
			toWrite(" 4 -> Imprimir o saldo corrente; ");
			toWrite(" 5 -> Sair do sistema; ");
			toWrite(" *** Faca bom uso *** ");

			cin >> op;

			switch(op) {
				case 1:
					if (qtdContasAbertas <= qtdContasTotal) {
						toWrite("Digite o numero da conta e o valor que deseja depositar: ");
						cin >> numConta >> valorGenerico;
						setContaBancaria(contaBancaria[qtdContasAbertas], numConta, valorGenerico);
						qtdContasAbertas++;
					} else {
						toWrite("Impossivel abrir novas contas.")
					}
					break;
				case 2:
					toWrite("Digite o numero da conta e o valor que deseja depositar: ");
					cin >> numConta >> valorGenerico;
					depositarValor(contaBancaria ,numConta, valorGenerico, qtdContasAbertas);
					break;
				case 3:
					toWrite("Digite o numero da conta e o valor que deseja sacar: ");
					cin >> numConta >> valorGenerico;
					sacarValor(contaBancaria ,numConta, valorGenerico, qtdContasAbertas);
					break;
				case 4:
					toWrite("Digite o numero da conta que deseja obter o saldo: ")
					cin >> numConta;
					imprimirSaldo(contaBancaria, numConta, qtdContasAbertas);
					break;
				case 5:
					toWrite("Obrigado por utilizar o sistema.");
					break;
				default:
					toWrite("Opcao invalida. Tente novamente ");
			}
			
		}while (op != 5);
	}		
	return 0;
}