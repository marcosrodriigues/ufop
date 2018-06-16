#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double x1, x2, y, passo, i = 0;
	
	do {
		cout << "Entre com os valores iniciais e finais de X: \n";
		cin >> x1 >> x2;
	} while (x2 < x1);
	
	do {
		cout << "Entre com o valor do passo: \n";
		cin >> passo;
	} while (passo <= 0);
	
	cout << "Pares ordenados: \n";
	
	while (x1 <= x2) {
		
		y = (pow(x1, 2) + 1) / (x1 + 2);
		
		cout << "(" << x1 << "," << y << ")\n";
		x1 += passo;
	}
	
	return 0;
} 