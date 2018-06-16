#include <iostream>
#include <iomanip>
#include "TContaBancaria.h"
using namespace std;

void setContaBancaria (TContaBancaria *conta, int numConta, double saldoInicial) {
	conta->numeroConta = numConta;
	conta->saldo = saldoInicial;
}

void imprimirSaldo (TContaBancaria conta, int numConta, int qtdContasAbertas) {
	int indexConta;
	indexConta = procurarConta(*conta, numConta, qtdContasAbertas);
	
	if (indexConta == -1) 
		toWrite("Numero da conta nao encontrado. Operacao nao realizada.");
	else {
		toWrite("Saldo da conta " << conta[indexConta].numeroConta << ": R$ " << fixed << setprecision(2) << conta[indexConta].saldoInicial);
	}
}

void sacarValor (TContaBancaria *conta, int numConta, double qtd, int qtdContasAbertas) {
	int indexConta;
	indexConta = procurarConta(*conta, numConta, qtdContasAbertas);
	
	if (indexConta == -1) 
		toWrite("Numero da conta nao encontrado. Operacao nao realizada.");
	else {
		if (conta[indexConta]->saldo >= qtd) {
			conta[indexConta]->saldo = conta[indexConta]->saldo - qtd;
			toWrite("Saque realizado com sucesso.");
		} else {
			toWrite("Impossivel sacar este valor. Saldo insuficiente. Operacao nao realizada.");
		}
	}
}

void depositarValor (TContaBancaria *conta, int numConta, double qtd, int qtdContasAbertas) {
	int indexConta;
	indexConta = procurarConta(*conta, numConta, qtdContasAbertas);
	
	if (indexConta == -1) 
		toWrite("Numero da conta nao encontrado. Operacao nao realizada.");
	else {
		if (qtd >= 0.0) {
			conta[indexConta]->saldo = conta[indexConta]->saldo + qtd;
			toWrite("Deposito realizado com sucesso.");
		} else {
			toWrite("Impossivel depositar valor negativo. Operacao nao realizada. ");
		}
	}
}

int procurarConta (TContaBancaria conta, int numConta, int totalContas) {
	for (int i = 0; i < totalContas; i++) {
		if (conta.numeroConta == numConta)
			return i;
	}
	
	return -1;
}

void toWrite(string message) {
	cout << message << endl;
}
