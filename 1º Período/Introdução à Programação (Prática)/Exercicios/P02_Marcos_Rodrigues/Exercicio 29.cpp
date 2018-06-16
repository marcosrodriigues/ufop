#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int X, Y, Z;
	
	cout << "Digite 3 valores: \n";
	cin >> X >> Y >> Z;
	
	/*
		Regra do Triangulo:
		Um dos lados deve ser maior que o modulo da subtração dos outros dois
		E
		Este mesmo lado deve ser menor que a soma dos outros dois
		Isto deve ser válido para os 3 lados.
		
		Bibliografia:
			http://www.mundoeducacao.com/matematica/condicao-existencia-um-triangulo.htm
	*/
	
	if ((abs(Y - Z) < X) && (X < Y + Z) && (abs(X - Z) < Y ) && (Y < X + Z) && (abs(Y - X) < Z) && (Z < Y + X))
		cout << "Os valores podem ser os lados de um triangulo.\n";
	else
		cout << "Os valores nao podem ser os lados de um triangulo.\n";

	return 0;
}