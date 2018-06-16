#include <iostream>
using namespace std;

int MDC (int x, int y) {
	if (x == y)
		return x;
	else if (x > y) 
		MDC (x - y, y);
	else 
		MDC (y - x, x);
	
}

int main () {

	int X, Y;

	cin >> X >> Y;
	
	while (X != 0 || Y != 0) {
		cout << MDC(X, Y) << endl;
		cin >> X >> Y;
	}
	
	return 0;
}