/*
	Marcos Rodrigues - 14.2.4341
	Matrizes.
	Exercício 02.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

	const int MAX = 5;
	
	
	double G[MAX][MAX], *SL, *SC;
	
	SL = (double*)calloc(MAX, sizeof(double));
	SC = (double*)calloc(MAX, sizeof(double));
	
	cout << "Digite " << (MAX * MAX) << " valores para a matriz: \n";
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> G[i][j];
		}
	}
	
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			SL[i] = SL[i] + G[i][j];
			SC[i] = SC[i] + G[j][i];
		}
	}
	
	cout << "Soma das linhas: "; 
	for (int i = 0; i < MAX; i++) {
		cout << SL[i] << " ";
	}
	
	cout << "\nSoma das colunas: "; 
	for (int i = 0; i < MAX; i++) {
		cout << SC[i] << " ";
	}
	
	return 0;
}