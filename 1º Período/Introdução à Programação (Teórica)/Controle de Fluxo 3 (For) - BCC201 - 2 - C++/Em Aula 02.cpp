/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Controle de Fluxo 3 (For) - Exercicio em aula - 02
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double senX, graus, radianos;
	const double PI = 3.14;
	bool sinal = true;
	int fatorial;
	
	do {
		cout << "Entre com o valor em radianos: ";
		cin >> radianos;
	} while (radianos < 0);

	graus = (180 / PI) * radianos;

	for(int i = 1; i <= 60; i = i + 2) {
		fatorial = 1;
		
		for(int k = i; k >= i; k--) {
			fatorial = fatorial * k;
		}
		
		if (sinal) {
			senX = senX + (pow(graus, i) / fatorial);
		}  else {
			senX = senX - (pow(graus, i) / fatorial);
		}
		
		sinal = !sinal;
	}

	
	cout << "Seno: " << senX;

	return 0;
}