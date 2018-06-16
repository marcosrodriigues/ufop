#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	double x;
	
	cout << "Entre com um valor:\n";
	cin >> x;
	
	if (x <= 1)
		cout << "O valor da funcao eh: 1";
	else if (x > 1 && x <= 2)
		cout << "O valor da funcao eh: 2";
	else if (x > 2 && x <= 3)
		cout << "O valor da funcao eh: " << pow(x, 2);
	else
		cout << "O valor da funcao eh: " << pow(x, 3);
	
	return 0;
}