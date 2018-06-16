/*
	Introdução à Programação
	Marcos Rodrigues - 14.2.4341
	Função - Exercício Em Casa - 01
*/

#include <iostream>
using namespace std;

double mediaHarmonica() {
	int a, b, c, d, e;
	double harmonica;
	
	do {
		cout << "Digite 5 valores inteiros e positivos: ";
		cin >> a >> b >> c >> d >> e;
	} while (a <= 0 || b <= 0 || c <= 0 || d <= 0 || e <= 0);
	
	harmonica = (5 / (((double)1 / a) + ((double)1 / b) + ((double)1 / c) + ((double)1 / d) + ((double)1 / e)));
	
	return harmonica;
	
}

int main() {
	
	double harmonica = mediaHarmonica();
	
	cout << "Valor da media harmonica: " << harmonica << endl;
	
	return 0;
}