#include <iostream>
using namespace std;

int main() {
	
	double v1, v2;
	
	cout << "Digite dois valores: \n";
	cin >> v1 >> v2;
	
	if ((v1 + v2) > 20)
		cout << "A soma dos valores digitados somando-os com 8 eh: " << (v1 + v2 + 8);
	else
		cout << "A soma dos valores digitados subtraindo-os com 5 eh: " << (v1 + v2 - 5);
		
	return 0;
}