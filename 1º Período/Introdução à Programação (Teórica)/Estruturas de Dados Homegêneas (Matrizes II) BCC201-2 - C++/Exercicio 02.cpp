/*
	Marcos Rodrigues - 14.2.4341
	Matrizes II
	Exercício 01
*/

#include <iostream>
#define MAX 3
using namespace std;

bool triangularSuperior(int matriz[MAX][MAX]);

int main() {

	int mat[MAX][MAX];

	cout << "Digite " << MAX * MAX << " elementos que irao compor a matriz: \n";
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> mat[i][j];
			
	cout << (triangularSuperior(mat) ? "Matriz trianguar superior." : "Matriz nao triangular superior");

	return 0;
}

bool triangularSuperior(int matriz[MAX][MAX]) {

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j <= i - 1; j++) {
			if (matriz[i][j] != 0) return false;
		}
	}

	return true;
}