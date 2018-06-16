/*
	Marcos Rodrigues - 13.2.4341
	Estrutura de Dados Heterogêneas II - Exercício
*/

#include <iostream>
#define MAX 50
using namespace std;

struct registro {
	string marca, modelo, cor, placa;
	int anoFabricacao;		
};

int main() {

	registro veiculo[MAX];
	int N, op;
	
	do {
		cout << "Digite quantos carros deseja cadastrar (Entre 1 e " << MAX << "): \n";
		cin >> N;
	} while (N < 1 || N > MAX);
	
	fflush(stdin);
	
	for (int i = 0; i < N; i++) {
		cout << " /*** Digite as informacoes do " << (i + 1) << ". carro. ***/" << endl;
		cout << "Marca: ";
		getline(cin, veiculo[i].marca);
		cout << "Modelo: ";
		getline(cin, veiculo[i].modelo);
		cout << "Cor: ";
		getline(cin, veiculo[i].cor);
		cout << "Placa: ";
		getline(cin, veiculo[i].placa);
		
		cout << "Ano de Fabricacao: ";
		cin >> veiculo[i].anoFabricacao;
		fflush(stdin);
		
		cout << endl;
		
	}

	cout << "Digite 1 para visualizar os veiculos cadastrados ou 0 para sair do programa. \n";
	cin >> op;
	
	if (op == 1) {
		for (int i = 0; i < N; i++) {
			cout << " /*** Informacoes do " << (i + 1) << ". veiculo. ***/" << endl;
			cout << "Marca: " << veiculo[i].marca << endl;
			cout << "Modelo; " << veiculo[i].modelo << endl;
			cout << "Cor:  " << veiculo[i].cor << endl;
			cout << "Placa: " << veiculo[i].placa << endl;
			cout << "Ano de Fabricacao: " << veiculo[i].anoFabricacao << endl;
			cout << endl;
		}
	}
	
	return 0;
}