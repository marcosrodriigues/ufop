/*
	Marcos Rodrigues - 13.2.4341
	Ponteiros II - Exercício 01
*/

#include <iostream>
using namespace std;

int **Transporta(int **M, int lin, int col);

int main () {

	int lin, col, **M = NULL, **M_Transporta = NULL;
	
	cout << "Digite o numero de linhas e colunas da matriz: " << endl;
	cin >> lin >> col;
	
	M = new int *[lin];
	for (int i = 0; i < lin; i++)
		M[i] = new int[col];

	cout << "Digite os valores da matriz: " << endl;
	for (int i = 0; i < lin; i++)
		for (int j = 0; j < col; j++)
			cin >> M[i][j];
			
	M_Transporta = Transporta(M, lin, col);
	
	cout << endl;
	
	cout << "Matriz Transporta: " << endl;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < lin; j++) {
			cout << M_Transporta[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

int **Transporta(int **M, int lin, int col) {
	//Criando uma nova matriz
	int **MatTrans = NULL, aux;
	//Definindo as colunas delas
	MatTrans = new int *[col];
	for (int i = 0; i < col; i++)
		MatTrans[i] = new int[lin];

	for(int i = 0; i < col; i++) {
		for (int j = 0; j < lin; j++) {
			MatTrans[i][j] = M[j][i];
		}
	}
		
	return MatTrans;
}
