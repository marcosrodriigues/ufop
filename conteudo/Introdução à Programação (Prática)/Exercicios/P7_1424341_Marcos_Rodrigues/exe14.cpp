#include <iostream>
using namespace std;

int main() {
	const int MAXi = 4, MAXj = 5;
	
	int Matriz[MAXi][MAXj], soma = 0;
	
	for (int i = 0; i < MAXi; i++) {
		for (int j = 0; j < MAXj; j++) {
			cin >> Matriz[i][j];
			soma = soma + Matriz[i][j];
		}
	}
	
	cout << soma;
	
	return 0;
}