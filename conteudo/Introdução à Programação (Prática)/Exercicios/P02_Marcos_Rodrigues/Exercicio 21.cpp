#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double peso, altura, IMC;
	
	cout << "Digite o seu peso e altura, respectivamente: \n";
	cin >> peso >> altura;
	
	IMC = peso / (pow(altura, 2));
	
	if (IMC < 20)
		cout << "Abaixo do peso.\n";
	else if (IMC >= 20 && IMC < 25)
		cout << "Peso normal.\n";
	else if (IMC >= 25 && IMC < 30)
		cout << "Sobre peso.\n";
	else if (IMC >= 30 && IMC < 40)
		cout << "Obeso.\n";
	else
		cout << "Obeso Morbido.\n";
	
	return 0;
}