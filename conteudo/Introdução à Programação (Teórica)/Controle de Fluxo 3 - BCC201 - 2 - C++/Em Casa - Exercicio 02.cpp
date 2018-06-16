#include <iostream>
using namespace std;

int main() {
	
	int i, numero, somaPar = 0, somaImpar = 0;
	
	cout << "Digite um numero: \n";
	cin >> numero;
	
	for(i = 0; i <= numero; i++) {
		if (i % 2 == 0)
			somaPar += i;
		else
			somaImpar += i;
	}
	
	cout << "\n";
	cout << "A soma dos numeros pares ate " << numero << " eh: " << somaPar << "\n";
	cout << "A soma dos numeros impares ate " << numero << " eh: " << somaImpar << "\n";

	return 0;
}