#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

void preencherMatriz(int **M, int i, int j);
void preencherRecursivo(int **M, int iAtual, int jAtual, int cAnt, int cNovo, int iMax, int jMax);

int main() {
	
	int i, j, iAtual, jAtual, corNova, **M;
	cin >> i >> j;
		
	//Alocando dinamicamente a matriz
	M = new int*[i];
	for (int k = 0; k < i; k++)
		M[k] = new int[j];
	
	preencherMatriz(M, i, j);
	
	cout << "Matriz Atual: " << endl;
	for(int m = 0; m < i; m++) {
		for (int n = 0; n < j; n++) {
			cout << M[m][n] << " ";
		}
		cout << endl;
	}
	
	cin >> iAtual >> jAtual >> corNova;
	
	preencherRecursivo(M, iAtual - 1, jAtual  - 1, M[iAtual  - 1][jAtual  - 1], corNova, i, j);
	
	cout << endl << "Matriz Nova: " << endl;
	for(int m = 0; m < i; m++) {
		for (int n = 0; n < j; n++) {
			cout << M[m][n] << " ";
		}
		cout << endl;
	}
	
	//Decalocando dinamicamente a matriz
	for (int k = 0; k < i; k++)
		delete[] M[k];
	delete[] M;
	
	return 0;
}

void preencherMatriz(int **M, int i, int j) {
	for(int m = 0; m < i; m++)
		for (int n = 0; n < j; n++)
			cin >> M[m][n];
}

void preencherRecursivo(int **M, int iAtual, int jAtual, int cAnt, int cNovo, int iMax, int jMax) {
	if (M[iAtual][jAtual] != cAnt)
		return;
	
	M[iAtual][jAtual] = cNovo;
	
	if (iAtual + 1 < iMax)
		preencherRecursivo(M, iAtual + 1, jAtual, cAnt, cNovo, iMax, jMax);
	
	if (iAtual - 1 >= 0)
		preencherRecursivo(M, iAtual - 1, jAtual, cAnt, cNovo, iMax, jMax);
	
	if (jAtual + 1 < jMax)
		preencherRecursivo(M, iAtual, jAtual + 1, cAnt, cNovo, iMax, jMax);
	
	if (jAtual - 1 >= 0)
		preencherRecursivo(M, iAtual, jAtual - 1, cAnt, cNovo, iMax, jMax);

	return;
}