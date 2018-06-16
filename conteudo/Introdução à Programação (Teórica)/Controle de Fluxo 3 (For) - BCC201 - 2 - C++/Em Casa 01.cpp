/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Controle de Fluxo 3 (For) - Exercicio em casa - 01
*/

#include <iostream>
using namespace std;

int main() {

	const double MAX = pow(10, -4);
	double senX = 0.0;
	int fatorial = 0, aux = 1;	
	bool sinal = true;
	
	while(senX > MAX) {
		
		fatorial = 1;
		
		for(int k = aux; k >= aux; k--) {
			fatorial = fatorial * k;
		}
		
		if (sinal) {
			senX = senX + (pow(1, aux) / fatorial);
		}  else {
			senX = senX - (pow(1, aux) / fatorial);
		}
		
		sinal = !sinal;
		
		aux = aux + 2;
	}


	return 0;
}