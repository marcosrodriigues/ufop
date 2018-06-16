#include <iostream>
#include <iomanip> // Biblioteca para usar o SETPRECISION
#include <cmath>
using namespace std;
using std::ios;

int main() {

	const int MAX = 15;
	int numero;
	double vetor[MAX];

	for(int i = 0; i < MAX; i++) {
		cout << "Digite o valor: ";
		cin >> numero;
		
		if (numero < 0)
			vetor[i] = -1;
		else
			vetor[i] = sqrt(numero);
	}
	
	
	/*
		Doumentação do precision; http://www.cplusplus.com/reference/iomanip/setprecision/
	*/
	
	//Define o SETPRECISION de todos os COUT pra 4.
	cout.precision(3);
	//Define que todo o COUT vai transformar o tipo de valor para FLOAT
	cout.setf(ios::fixed, ios::floatfield);
	
	for (int i = 0; i < MAX; i++) {
		cout << "Raiz quadrada do " << (i + 1) << ". numero: " << vetor[i] << endl;
	}
	
	return 0;
}