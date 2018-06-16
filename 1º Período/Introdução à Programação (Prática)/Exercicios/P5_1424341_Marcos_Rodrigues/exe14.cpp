#include <iostream>
using namespace std;

int isTaller(int n1, int n2) {
	return (n1 > n2) ? n1 : n2;
}

int main() {

	int num1, num2;
	
	cin >> num1 >> num2;
	
	while (num1 != 0 || num2 != 0) {
		cout << isTaller(num1, num2) << endl;
		cin >> num1 >> num2;
	}

	return 0;
}