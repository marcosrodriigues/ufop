#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double A, B;
	
	cout << "Digite dois valores: \n";
	cin >> A >> B;
	
	if(B != 0.0) {
		//FMOD é uma função para pegar o resto da divisão de números DOUBLE
		if (fmod(A, B) == 0.0)
		cout << "O primeiro numero eh divisivel pelo segundo.\n";
		else
			cout << "O primeiro numero nao eh divisivel pelo segundo.\n";
	} else {
		cout << "Segundo valor invalido para uma divisao\n";
	}
	
		
	return 0;
}