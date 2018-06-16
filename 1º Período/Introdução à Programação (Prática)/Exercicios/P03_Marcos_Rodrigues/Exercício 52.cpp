/*
	Implementar um programa para calcular o sen(X). O valor de X deverá ser digitado em graus. 
	O valor do seno de X será calculado pela  soma dos 15 primeiros termos da série a seguir: 
	
	sen(X) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11!...
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int X;
	double senoX = 0.0;
	bool Somar = true;
	int fatorial;
	
	cout << "Entre com o valor de X (em graus): \n";
	cin >> X;
		
	for(int i = 1; i <= 30; i = i + 2) {
		
		fatorial = 1;
		//Calculando o fatorial;
		for(int j = i; j >= 1; j--) {
			fatorial = fatorial * j;
		}
		
		if (Somar) {
			senoX = senoX + (pow(X, i) / fatorial);
		} else {
			senoX = senoX - (pow(X, i) / fatorial);
		}
		
		Somar = !Somar;
	}
	
	cout << "O valor de Sen(X) eh: " << senoX;
	
	return 0;
}