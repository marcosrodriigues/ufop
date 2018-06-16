#include <iostream>
using namespace std;

int main() {

	const int MAX = 2;
	double determinante, aux, MatAdjunta[MAX][MAX], Matriz[MAX][MAX];
	
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> Matriz[i][j];
		}
	}

	determinante = Matriz[0][0] * Matriz[1][1] - Matriz[1][0] * Matriz[0][1];
	cout << determinante << endl;
		
	MatAdjunta[0][0] = Matriz[1][1];
	MatAdjunta[1][1] = Matriz[0][0];
	
	MatAdjunta[0][1] = Matriz[0][1] * -1;
	MatAdjunta[1][0] = Matriz[1][0] * -1;
	
	
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MatAdjunta[i][j] = (double)MatAdjunta[i][j] * (1 / determinante);
			cout << MatAdjunta[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}