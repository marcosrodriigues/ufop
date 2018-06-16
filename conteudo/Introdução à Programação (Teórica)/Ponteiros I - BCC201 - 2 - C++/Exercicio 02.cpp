/*
	Marcos Rodrigues - 14.2.4341
	Ponteiros I - Exercício 02.
*/
#include <iostream>
using namespace std;
void dobro(double v1, double *v2);

int main () {

	double val1, *val2;
	
	cout << "Digite o valor de um numero: " << endl;
	cin >> val1;
	
	dobro(val1, val2);
	
	cout << "Dobro do primeiro valor: " << *val2 << endl;

	return 0;
}

void dobro(double v1, double *v2) {
	*v2 = v1 * 2;
}