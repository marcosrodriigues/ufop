/*
	Sendo  H = 1 - 1/2 + 1/3 - 1/4... 1/N, faça  um  programa  para  gerar  o  número  H.  O número N é lido do teclado. 
*/

#include <iostream>
using namespace std;

int main() {

	double H = 0.0;
	int N;
	bool Somar = true;
	
	cout << "Digite um valor para N: \n";
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		if (Somar) {
			H = H + (1.0 / i);
		} else {
			H = H - (1.0 / i);
		}
		Somar = !Somar;
	}
	
	cout << "\nO valor de H eh: " << H;	

	return 0;
}