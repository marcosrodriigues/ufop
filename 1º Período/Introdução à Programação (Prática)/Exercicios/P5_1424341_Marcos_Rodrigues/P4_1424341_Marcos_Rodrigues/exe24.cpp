#include <iostream>
#include <cmath>
using namespace std;

int main () {

	const int MAX = 100;

	//Nome da variável é B pois assim estava no enunciado.
	int B[MAX], somatorio = 0;
	
	cout << "Digite " << MAX << " valores numericos: \n";
	for (int i = 0; i < MAX; i++) {
		cin >> B[i];
	}
	
	for (int i = 0; i < (MAX / 2); i++) {
		somatorio += pow(B[i] - B[MAX - (i + 1)], 3);
	}
	
	cout << "Somatorio: " << somatorio;
	
	return 0;
}