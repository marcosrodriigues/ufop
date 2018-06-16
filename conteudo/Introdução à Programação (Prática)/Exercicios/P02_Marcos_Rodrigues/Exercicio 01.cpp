#include <iostream>
using namespace std;

int main() {
	double value;
	
	cout << "Digite um valor: \n";
	cin >> value;
	
	if (value > 20)
		cout << "Valor digitado: " << value;
	
	return 0;
}