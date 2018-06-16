#include <iostream>
using namespace std;

int main() {
	const int MAX = 10;
	
	int Matriz[MAX][MAX], soma = 0;
	
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cin >> Matriz[i][j];
	}
	
	for (int i = 0; i < MAX; i++) {
		for (int j = (i + 1); j < MAX; j++) {
			soma = soma + Matriz[i][j];
		}
	}
	
	cout << soma;
	
	return 0;
}