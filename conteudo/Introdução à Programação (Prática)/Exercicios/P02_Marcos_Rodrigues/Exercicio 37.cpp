#include <iostream>
using namespace std;

int main() {
	int idade;
	double peso, qtdML, dosagem;
	
	//O medicamento possui 500mg por ML.
	const int EachML = 500;
	//Cada ML possui 20 gotas.
	const int EachMLGota = 20;
		
	cout << "Entre com a idade: \n";
	cin >> idade;
	cout << "Entre com o peso: \n";
	cin >> peso;
	
	//Peso maior ou igual a zero pois existem pessoas que nascem anémicas e pesam 800 gramas.
	if(idade >= 0 && peso >= 0){
		if (idade >= 12){
			if (peso >= 60) {
				qtdML = 1000.0 / EachML;
			} else {
				qtdML = 875.0 / EachML;
			}
			dosagem = qtdML * EachMLGota;
		} else {
			if (peso >= 5 && peso <= 9) {
				qtdML = 125.0 / EachML;
			} else if (peso >= 9.1 && peso <= 16) {
				qtdML = 250.0 / EachML;
			} else if (peso >= 16.1 && peso <= 24) {
				qtdML = 375.0 / EachML;
			} else if (peso >= 24.1 && peso <= 30) {
				qtdML = 500.0 / EachML;
			} else if (peso >= 30) {
				qtdML = 750.0 / EachML;
			} else {
				cout << "Peso invalido";
				return 1;
			}
			
			dosagem = qtdML * EachMLGota;
		}
		
		cout << "O paciente precisara tomar " << qtdML << " Mls do medicamento.\nIsto equivale a " << dosagem << " gotas.";
	} else {
		cout << "Dados invalidos";
		return 1;
	}
	
	return 0;
}