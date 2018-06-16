#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double A;
	bool sim = false;
	
	cout << "Digite um valor: \n";
	cin >> A;
	
	 if(fmod(A, 10) == 0) {
		cout << "O valor eh divisivel por 10.\n";
		sim = true;
	}
		
	if(fmod(A, 5) == 0) {
		cout << "O valor eh divisivel por 5.\n";
		sim = true;
	}	
		
	if(fmod(A, 2) == 0) {
		cout << "O valor eh divisivel por 2.\n";
		sim = true;
	}

	if (!sim)
		cout << "O valor nao eh divisivel por 10, nem por 5 e nem por 2.\n";
	
	return 0;
}