#include <iostream>
using namespace std;;

int MDC (int X, int Y) {
	if (Y == 0 || X == Y) 
		return X;
	
	int md = (X > Y) ? MDC(Y, X % Y) : MDC(X, Y % X);
	return md;
}

int main () {
	
	int X, Y;

	do {
		cin >> X >> Y;
	} while (X < 0 || Y < 0);
	
	cout << MDC(X, Y) << endl;
	
	return 0;
}