/*
	Marcos Rodrigues - 14.2.4341
	Matrizes II
	Exercício 01
*/

#include <iostream>
#define MAX 3
using namespace std;

bool matrizSimetrica(int matriz[MAX][MAX]);

int main() {

	int mat[MAX][MAX];

	cout << "Digite " << MAX * MAX << " elementos que irao compor a matriz: \n";
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> mat[i][j];
			
	cout << (matrizSimetrica(mat) ? "Matriz simetrica." : "Matriz nao simetrica");

	return 0;
}

bool matrizSimetrica(int matriz[MAX][MAX]) {

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i != j) {
				if (matriz[i][j] == matriz[j][i]) {
					continue;
				} else {
					return false;
				}
			}
		}
	}

	return true;
}