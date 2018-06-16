#include <iostream>
using namespace std;;

int somarNumeros (int A, int B) {
	
	if (B != 0) {
		A = somarNumeros(++A, --B);
	}
	return A;
}

int main () {
	
	int X, Y;
	
	do {
		cin >> X >> Y;
	} while (X < 0 || Y < 0);

	cout << somarNumeros(X, Y) << endl;
	
	return 0;
}