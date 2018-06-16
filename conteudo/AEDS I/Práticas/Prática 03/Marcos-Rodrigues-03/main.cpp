#include <iostream>
using namespace std;;

int multiplicarNumeros (int A, int B) {
	if (B == 0) 
		return 0;
	if (B == 1) 
		return A;	
	
	return A + multiplicarNumeros(A, --B);;
}

int main () {
	
	int X, Y;

	do {
		cin >> X >> Y;
	} while (X < 0 || Y < 0);
	
	cout << multiplicarNumeros(X, Y) << endl;

	return 0;
}