#include <iostream>
using namespace std;

int main() {

	const int MAX = 10;
	
	int MatA[MAX][MAX], MatResult[MAX][MAX], aux = 0;
	
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)  {
			cin >> MatA[i][j];
			MatResult[i][j] = MatA[i][j];
		}
		
	}
	
	//Trocando a segunda linha com a oitava
	for (int i = 0; i < MAX; i++) {
		aux = MatResult[7][i];
		MatResult[7][i] = MatResult[1][i];
		MatResult[1][i] = aux;
	}
	
	//Trocando a quarta coluna com a decima
	for (int i = 0; i < MAX; i++) {
		aux = MatResult[i][3];
		MatResult[i][3] = MatResult[i][9];
		MatResult[i][9] = aux;
	}		
	
	
	for (int i = 0, j = 9; i < MAX; i++, j--) {
		aux = MatResult[i][i];
		MatResult[i][i] = MatResult[i][j];
		MatResult[i][j] = aux;
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)  {
			cout << MatResult[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}